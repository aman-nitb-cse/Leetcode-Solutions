// Last updated: 6/24/2026, 3:30:01 AM
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        unordered_map<int,int> mp;
        // forword
        for(int i = n - 1; i >= 0; i--){
            if(!mp.count(nums[i])) mp[nums[i]] = INT_MIN;
            mp[nums[i]] = max(mp[nums[i]], i - n);
        }

        for(int i = 0; i < n; i++){
            dp[i] = min(dp[i], i - mp[nums[i]]);
            mp[nums[i]] = i;
        }

        // backword
        mp.clear();
        for(int i = 0; i < n; i++){
            if(!mp.count(nums[i])) mp[nums[i]] = INT_MAX;
            mp[nums[i]] = min(mp[nums[i]], i + n);
        }

        for(int i = n - 1; i >= 0; i--){
            dp[i] = min(dp[i], mp[nums[i]] - i);
            mp[nums[i]] = i;
        }

        vector<int> ans;
        for(auto &i : queries){
            if(dp[i] >= n) dp[i] = -1;
            ans.push_back(dp[i]);
        }

        return ans;
    }
};
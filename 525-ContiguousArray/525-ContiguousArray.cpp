// Last updated: 8/20/2026, 9:03:43 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++) nums[i] += nums[i - 1];

        for(int i = 0; i < n; i++) nums[i] = 2 * nums[i] - i;

        unordered_map<int,vector<int>> mp = {{1, {INT_MAX, -1}}}; // mp[x] = {even, odd};
        int ans = 0;
        for(int i = 0; i < n; i++){
            auto &v = mp[nums[i]];

            if(v.empty()) v = {INT_MAX, INT_MAX};

            if(v[i & 1] == INT_MAX) v[i & 1] = i;
            else ans = max(ans, i - v[i & 1]);
        }
        return ans;
    }
};
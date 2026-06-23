// Last updated: 6/24/2026, 3:26:45 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            vector<int> v(2);
            for(int j = 0; j < nums.size(); j++){
                int rem = nums[j] % k;
                v[j & 1] += min({abs(i - rem), abs(i - rem + k), abs(i - rem - k)});
            }
            ans.push_back(v);
        }

        int res = INT_MAX;
        for(int i = 0; i < k; i++){
            int mini = INT_MAX;
            for(int j = 0; j < k; j++){
                if(i == j) continue;
                mini = min(mini, ans[j][1]);
            }
            res = min(res, ans[i][0] + mini);
        }
        return res;
    }
};
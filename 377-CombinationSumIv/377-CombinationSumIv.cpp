// Last updated: 8/20/2026, 9:07:28 PM
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int &val : nums) 
                if(i - val >= 0 && dp[i] < INT_MAX) dp[i] += dp[i - val];
        }
        return dp.back();
    }
};
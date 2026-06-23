// Last updated: 6/24/2026, 3:28:53 AM
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        vector<int> dp(20000, -1);
        dp[0] = 0;

        for(int &i : nums){
            vector<int> copy = dp;
            for(int j = 0; j < 20000; j++){
                if(dp[j] != -1) copy[j ^ i] = max(dp[j ^ i], 1 + dp[j]);
            }
            dp = copy;
        }
        if(dp[target] == -1) return -1;
        return nums.size() - dp[target];
    }
};
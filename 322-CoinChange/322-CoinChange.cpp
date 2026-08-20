// Last updated: 8/20/2026, 9:08:49 PM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int &val : coins) {
                if(i - val >= 0) dp[i] = min(dp[i], 1 + dp[i - val]);
            }
        }
        return dp.back() < 1e9 ? dp.back() : -1;
    }
};
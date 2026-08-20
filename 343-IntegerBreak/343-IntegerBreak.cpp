// Last updated: 8/20/2026, 9:08:16 PM
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n);

        for(int i = 1; i < n; i++){
            dp[i] = i;
            for(int j = 1; j <= i / 2; j++){
                dp[i] = max(dp[i], dp[i - j] * dp[j]);
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n / 2; i++){
            ans = max(ans, dp[i] * dp[n - i]);
        }
        return ans;
    }
};
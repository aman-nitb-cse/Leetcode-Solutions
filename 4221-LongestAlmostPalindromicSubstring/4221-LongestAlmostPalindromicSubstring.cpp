// Last updated: 6/24/2026, 3:27:55 AM
class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }

        int best = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j] <= 1)
                    best = max(best, j - i + 1);
            }
        }

        return best;
    }
};
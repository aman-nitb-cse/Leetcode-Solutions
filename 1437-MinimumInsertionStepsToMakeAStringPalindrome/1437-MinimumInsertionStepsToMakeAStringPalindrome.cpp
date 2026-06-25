// Last updated: 6/25/2026, 11:17:06 PM
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp.front().back();
    }
};
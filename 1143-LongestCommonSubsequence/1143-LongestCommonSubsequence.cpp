// Last updated: 11/6/2026, 5:07:07 AM
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int m = a.size();
        int n = b.size();

        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);

                if(a[i] == b[j]) dp[i][j] = max(dp[i][j], 1 + ((i && j) ? dp[i - 1][j - 1] : 0));
            }
        }
        return dp[m - 1][n - 1];
    }
};
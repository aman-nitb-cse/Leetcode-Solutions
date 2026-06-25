// Last updated: 6/25/2026, 11:37:05 PM
class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                if(i == m && j == n) dp[i][j] = 0;
                else if(i == m) dp[i][j] = dp[i][j + 1] + b[j];
                else if(j == n) dp[i][j] = dp[i + 1][j] + a[i];
                else if(a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = min(a[i] + dp[i + 1][j], b[j] + dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};
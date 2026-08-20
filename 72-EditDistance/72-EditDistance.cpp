// Last updated: 8/20/2026, 9:16:57 PM
class Solution {
public:
    int minDistance(string &a, string &b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = m; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                if(i == m) dp[i][j] = n - j;
                else if(j == n) dp[i][j] = m - i;
                else if(a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = 1 + min({dp[i + 1][j], dp[i + 1][j + 1], dp[i][j + 1]});
            }
        }

        return dp[0][0];
    }
};
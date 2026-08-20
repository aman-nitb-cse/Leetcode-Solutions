// Last updated: 8/20/2026, 9:17:19 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& dp) {
        if(dp[0][0]) return 0;
        int m = dp.size(), n = dp[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i + j == 0) dp[i][j] = 1;
                else if(dp[i][j]) dp[i][j] = 0;
                else {
                    if(i) dp[i][j] += dp[i - 1][j];
                    if(j) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
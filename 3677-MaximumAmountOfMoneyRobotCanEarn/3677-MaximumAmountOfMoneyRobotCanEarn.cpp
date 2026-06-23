// Last updated: 6/24/2026, 3:30:10 AM
class Solution {
public:
    const int NI = -1e9;
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int dp[m][n][3];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!i && !j){
                    dp[i][j][0] = coins[i][j];
                    dp[i][j][1] = 0;
                    dp[i][j][2] = 0;
                    continue;
                }
                int prev0 = max(i ? dp[i - 1][j][0] : NI, j ? dp[i][j - 1][0] : NI);
                int prev1 = max(i ? dp[i - 1][j][1] : NI, j ? dp[i][j - 1][1] : NI);
                int prev2 = max(i ? dp[i - 1][j][2] : NI, j ? dp[i][j - 1][2] : NI);

                // simply take
                dp[i][j][0] = prev0 + coins[i][j];
                dp[i][j][1] = prev1 + coins[i][j];
                dp[i][j][2] = prev2 + coins[i][j];
                
                // Think for skip
                if(coins[i][j] < 0) {
                    dp[i][j][1] = max(dp[i][j][1], prev0);
                    dp[i][j][2] = max(dp[i][j][2], prev1);
                }
            }
        }
        return *ranges::max_element(dp[m-1][n-1]);
    }
};
// Last updated: 11/6/2026, 5:05:26 AM
class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!mat[i][j]) continue;
                dp[i][j] = 1;
                if(i && j){
                    dp[i][j] += min({
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    });
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
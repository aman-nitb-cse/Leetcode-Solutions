// Last updated: 6/24/2026, 3:29:31 AM
class Solution {
public:
    int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int,int>>> dp(m + 1, vector<pair<int,int>>(n + 1));
        dp[0][0] = {1, 0}; // dp[i][j] = {letf, up}

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                auto &[left, up] = dp[i][j];
                if(i){
                    up += dp[i - 1][j].first;
                    up %= mod;
                    if(0 == grid[i - 1][j]) up += dp[i - 1][j].second;
                    up %= mod;
                }
                if(j){
                    left += dp[i][j - 1].second;
                    left %= mod;
                    if(0 == grid[i][j - 1]) left += dp[i][j - 1].first;
                    left %= mod;
                }
            }
        }
        return (dp[m - 1][n - 1].first + dp[m - 1][n - 1].second) % mod;
    }
};
// Last updated: 6/24/2026, 3:28:08 AM
class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0][g[0][0]] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                bitset<1024> up = i ? dp[i - 1][j] : 0;
                bitset<1024> left = j ? dp[i][j - 1] : 0;
                
                for(int x = 0; x < 1024; x++){
                    if(up[x] || left[x]) dp[i][j].set(x ^ g[i][j]);
                }
            }
        }

        for(int x = 0; x < 1024; x++){
            if(dp[m - 1][n - 1][x]) return x;
        }
        return 0;
    }
};
// Last updated: 6/24/2026, 3:29:51 AM
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int>(201)));


        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int v = 0; v <= 200; v++){
                    dp[i][j][v] = dp[i - 1][j][v] + dp[i][j - 1][v] - dp[i - 1][j - 1][v];
                }
                int x = mat[i - 1][j - 1];

                for(int v = 0; v < x; v++){
                    dp[i][j][v]++;
                }
            }
        }

        auto get = [&](int v, int r1, int c1, int r2, int c2){
            return dp[r2 + 1][c2 + 1][v] - dp[r1][c2 + 1][v] - dp[r2 + 1][c1][v] + dp[r1][c1][v];
        };

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = mat[i][j];
                if(x == 0) continue;

                int cnt = get(x, max(0, i - x), max(0, j - x), min(m - 1, i + x), min(n - 1, j + x));

                for(int r : {i - x, i + x}){
                    for(int c : {j - x, j + x}){
                        if(r >= 0 && r < m && c >= 0 && c < n && mat[r][c] > x){
                            cnt--;
                        }
                    }
                }
                ans += !cnt;
            }
        }
        return ans;
    }
};
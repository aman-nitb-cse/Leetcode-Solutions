// Last updated: 6/24/2026, 3:29:27 AM
class Solution {
public:
    static constexpr int mod = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<vector<int>> up(n, vector<int>(m));
        vector<vector<int>> down(n, vector<int>(m));

        // Initialization 
        for(int p = 0; p < m; p++) {
            down[0][p] = 1;
            if(p) {
                down[0][p] += down[0][p - 1];
                down[0][p] %= mod;
            }
        }

        for(int p = m - 1; p >= 0; p--) {
            up[0][p] = 1;
            if(p + 1 < m) {
                up[0][p] += up[0][p + 1];
                up[0][p] %= mod;
            }
        }

        for(int i = 1; i < n; i++) {

            for(int p = 0; p < m; p++) {

                if(p + 1 < m) down[i][p] = up[i - 1][p + 1];

                if(p) {
                    down[i][p] += down[i][p - 1];
                    down[i][p] %= mod;
                }
            }

            for(int p = m - 1; p >= 0; p--) {
                
                if(p) up[i][p] = down[i - 1][p - 1];

                if(p + 1 < m) {
                    up[i][p] += up[i][p + 1];
                    up[i][p] %= mod;
                }
            }
        }

        return (up[n - 1][0] + down[n - 1][m - 1]) % mod;
    }
};
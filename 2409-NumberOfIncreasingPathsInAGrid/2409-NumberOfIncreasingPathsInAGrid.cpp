// Last updated: 6/25/2026, 11:12:08 PM
class Solution {
public:
    int m, n, mod = 1e9 + 7;

    vector<vector<int>> dp;

    int dir[5] = {1, 0, -1, 0, 1};

    int f(vector<vector<int>>& mat, int i, int j){

        if(dp[i][j]) return dp[i][j];

        for(int d = 0; d < 4; d++){

            int ni = i + dir[d];
            int nj = j + dir[d + 1];

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && mat[ni][nj] > mat[i][j]){

                dp[i][j] = (dp[i][j] + f(mat, ni, nj)) % mod;
            }
        }

        return dp[i][j] = (1 + dp[i][j]) % mod;
    }

    int countPaths(vector<vector<int>>& mat) {

        m = mat.size();
        n = mat[0].size();

        int ans = 0;

        dp.assign(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = (ans + f(mat, i, j)) % mod;
            }
        }

        return ans;
    }
};




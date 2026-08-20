// Last updated: 8/20/2026, 9:08:34 PM
class Solution {
public:
    int m, n, ans = 0;

    vector<vector<int>> dp;

    int dir[5] = {1, 0, -1, 0, 1};

    int f(vector<vector<int>>& mat, int i, int j){

        if(dp[i][j]) return dp[i][j];

        for(int d = 0; d < 4; d++){

            int ni = i + dir[d];
            int nj = j + dir[d + 1];

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && mat[ni][nj] > mat[i][j]){

                dp[i][j] = max(dp[i][j], f(mat, ni, nj));
            }
        }

        return ++dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {

        m = mat.size();
        n = mat[0].size();

        dp.assign(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                ans = max(ans, f(mat, i, j));
            }
        }

        return ans;
    }
};
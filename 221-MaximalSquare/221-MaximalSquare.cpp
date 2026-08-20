// Last updated: 8/20/2026, 9:11:10 PM
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3)));
        // dp[i][j] = {left, up, length}

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == '0') continue;

                dp[i][j] = {1, 1, 1};
                if(i) dp[i][j][0] += dp[i - 1][j][0];
                if(j) dp[i][j][1] += dp[i][j - 1][1];

                int l = min(dp[i][j][0], dp[i][j][1]);

                if(i && j) dp[i][j][2] = min(l, dp[i - 1][j - 1][2] + 1);
                ans = max(ans, dp[i][j][2]);
            }
        }
        return ans * ans;
    }
};
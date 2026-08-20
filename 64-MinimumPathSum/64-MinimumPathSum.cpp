// Last updated: 8/20/2026, 9:17:11 PM
class Solution {
public:
    int minPathSum(vector<vector<int>>& dp) {
        int m = dp.size(), n = dp[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                int left = INT_MAX, up = INT_MAX;
                if(r) up = dp[r - 1][c];
                if(c) left = dp[r][c - 1];

                if(left != INT_MAX || up != INT_MAX) dp[r][c] += min(left, up);
            }
        }
        
        // return dp
        return dp[m - 1][n - 1];
    }
};
// Last updated: 8/20/2026, 9:04:45 PM
class Solution {
public:
    // Space optimization O(m * n)
    int findMaxForm(vector<string>& w, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for(int i = w.size() - 1; i >= 0; i--){
            int ones = ranges::count(w[i], '1');
            int zeros = w[i].size() - ones;
            for(int j = m; j >= 0; j--){
                for(int k = n; k >= 0; k--){
                    if(j >= zeros && k >= ones) dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
                }
            }
        }
        return dp[m][n];
    }
};
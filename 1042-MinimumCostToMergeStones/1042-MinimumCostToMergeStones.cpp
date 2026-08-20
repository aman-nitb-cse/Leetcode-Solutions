// Last updated: 8/20/2026, 8:56:30 PM
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        
        if ((n - 1) % (K - 1) != 0) return -1;
        
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + K - 1; j < n; j++) {
                // now solve for subproblem arr[i..j]
                dp[i][j] = 1e9;
                
                for (int mid = i; mid < j; mid += K - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }
                
                if ((j - i) % (K - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
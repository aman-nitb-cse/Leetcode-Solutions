// Last updated: 6/25/2026, 11:17:20 PM
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();

        vector<vector<int>> changes(n, vector<int>(n, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(j - i == 1) changes[i][j] = (s[i] != s[j]);
                else changes[i][j] = changes[i + 1][j - 1] + (s[i] != s[j]);
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));

        for(int i = 0; i < n; i++) dp[i][1] = changes[0][i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                for(int p = 2; p <= k; p++){
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + changes[j + 1][i]);
                }
            }
        }

        return dp[n - 1][k];
    }
};
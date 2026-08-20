// Last updated: 8/20/2026, 8:44:05 PM
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool> (n));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(j - i <= 1) pal[i][j] = (s[i] == s[j]);
                else pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
            }
        }

        int cnt = 0;

        vector<int> dp(n + 1);

        for(int i = n - 1; i >= 0; i--){
            dp[i] = dp[i + 1];
            for(int j = i + k - 1; j < n; j++){
                if(pal[i][j]) dp[i] = max(dp[i], 1 + dp[j + 1]);
            }
        }

        return dp[0];
    }
};
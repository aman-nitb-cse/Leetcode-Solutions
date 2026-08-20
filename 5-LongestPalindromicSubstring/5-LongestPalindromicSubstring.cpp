// Last updated: 8/20/2026, 9:20:48 PM
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n));
        int size = 0;
        int start, end;

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j]) {
                    if(j - i < 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = false;

                if(dp[i][j] && j - i + 1 > size) {
                    start = i;
                    end = j;
                    size = j - i + 1;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
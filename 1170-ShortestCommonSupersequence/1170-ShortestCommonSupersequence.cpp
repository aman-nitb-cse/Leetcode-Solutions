// Last updated: 6/25/2026, 11:18:24 PM
class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = a.size(), n = b.size();

        int dp[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i] == b[j]) {
                    dp[i][j] = 1;
                    if(i && j) dp[i][j] += dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);
                }
            }
        }

        int i = m - 1, j = n - 1;
        string ans = "";
        while(i >= 0 && j >= 0){
            if(a[i] == b[j]){
                ans += a[i];
                i--;
                j--;
            }
            else if(i == 0) ans += b[j--];
            else if(j == 0 || dp[i - 1][j] > dp[i][j - 1]) ans += a[i--];
            else ans += b[j--];
        }
        while(i >= 0) ans += a[i--];
        while(j >= 0) ans += b[j--];
        ranges::reverse(ans);
        return ans;
    }
};
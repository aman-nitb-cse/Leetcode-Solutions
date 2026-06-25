// Last updated: 6/25/2026, 11:14:59 PM
class Solution {
public:
    vector<vector<bool>> flag;
    vector<vector<bool>> dp;
    bool checkPartitioning(string s) {
        int n = s.size();
        flag.assign(n, vector<bool>(n, false));
        dp.assign(n, vector<bool>(4, false));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] != s[j]) flag[i][j] = false;
                else if(j - i <= 1) flag[i][j] = true;
                else flag[i][j] = flag[i + 1][j - 1];
            }
        }

        // Tabulation
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(flag[j][i]){
                    if(j == 0) dp[i][1] = true;
                    else {
                        dp[i][1] = dp[i][1] || dp[j - 1][0];
                        dp[i][2] = dp[i][2] || dp[j - 1][1];
                        dp[i][3] = dp[i][3] || dp[j - 1][2];
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};
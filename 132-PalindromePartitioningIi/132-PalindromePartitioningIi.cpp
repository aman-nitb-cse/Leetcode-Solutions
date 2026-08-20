// Last updated: 8/20/2026, 9:13:50 PM
class Solution {
public:
    vector<vector<bool>> flag;
    vector<int> dp;
    int minCut(string s) {
        int n = s.size();
        flag.assign(n, vector<bool>(n, false));
        dp.assign(n, 1e9);

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] != s[j]) flag[i][j] = false;
                else if(j - i <= 1) flag[i][j] = true;
                else flag[i][j] = flag[i + 1][j - 1];
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(flag[j][i]) {
                    if(j) dp[i] = min(dp[i], 1 + dp[j - 1]);
                    else dp[i] = min(dp[i], 1);
                }
            }
        }
        return dp.back() - 1;
    }
};
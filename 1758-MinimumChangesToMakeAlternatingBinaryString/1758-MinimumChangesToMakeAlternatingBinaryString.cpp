// Last updated: 11/6/2026, 4:59:18 AM
class Solution {
public:
    int minOperations(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(2));

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') dp[i][1] = 1;
            else dp[i][0] = 1;

            if(i){
                dp[i][0] += dp[i - 1][1];
                dp[i][1] += dp[i - 1][0];
            }
        }

        return min(dp.back().back(), dp.back().front());
    }
};





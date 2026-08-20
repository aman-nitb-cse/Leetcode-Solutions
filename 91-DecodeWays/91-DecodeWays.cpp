// Last updated: 8/20/2026, 9:16:00 PM
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 1) return s != "0";
        // create DP
        vector<int> dp(s.size());

        // Base Case
        if(s[0] != '0') dp[0] = 1;
        if(s[0] == '1' || (s[0] == '2' && s[1] < '7')) dp[1] = 1;
        if(s[1] != '0') dp[1] += dp[0];

        // Fill the table
        for(int i = 2; i < s.size(); i++){
            if(s[i] != '0') dp[i] += dp[i - 1];
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};
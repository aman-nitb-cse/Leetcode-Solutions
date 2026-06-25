// Last updated: 6/25/2026, 11:37:22 PM
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<int> dp(n / 2 + 2);
        dp[0] = true;

        for(int i = n - 1; i >= 0; i--){
            auto copy = dp;
            for(int j = 0; j <= n / 2; j++){
                dp[j] = 0;
                if(s[i] == '(' || s[i] == '*') dp[j] |= copy[j + 1];
                if((s[i] == ')' || s[i] == '*') && j) dp[j] |= copy[j - 1];
                if(s[i] == '*') dp[j] |= copy[j];
            }
        }
        return dp[0];
    }
};
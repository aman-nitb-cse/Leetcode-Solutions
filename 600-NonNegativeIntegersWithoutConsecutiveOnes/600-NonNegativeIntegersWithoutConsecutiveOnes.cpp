// Last updated: 8/20/2026, 9:02:32 PM
class Solution {
public:
    string to_binary(int n){
        string s = "";
        while(n){
            s += (n & 1) + '0';
            n >>= 1;
        }
        ranges::reverse(s);
        return s;
    }
    int dp[32][2][2];
    int digitDP(string &s, int i = 0, int tight = 1,int prev1 = 0){
        if(i == s.size()) return 1;
        char limit = tight ? s[i] : '1';
        auto &_dp = dp[i][tight][prev1];
        if(_dp != -1) return _dp;

        // take 0
        _dp = digitDP(s, i + 1, tight && ('0' == limit), 0);

        // take 0
        if('1' == limit && !prev1) _dp += digitDP(s, i + 1, tight && ('1' == limit), 1);
        return _dp;
    }
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        auto s = to_binary(n);
        return digitDP(s);
    }
};
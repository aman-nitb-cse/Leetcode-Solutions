// Last updated: 8/20/2026, 9:10:39 PM
class Solution {
public:
    long long dp[12][2][12];

    long long digitDP(string &s, int i, int tight, int count){
        if(i == s.size()) return count;
        auto &_dp = dp[i][tight][count];
        if(_dp != -1) return _dp;

        char limit = tight ? s[i] : '9';
        _dp = 0;

        for(int d = '0'; d <= limit; d++){
            _dp += digitDP(
                s,                      
                i + 1, 
                tight && (d == limit),  // tight for next
                count + (d == '1')        // inc count if digit is 1
            );
        }

        return _dp;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return digitDP(s, 0, 1, 0);
    }
};
// Last updated: 6/25/2026, 11:18:51 PM
class Solution {
public:
    // total - all unique digits
    int dp[10][2][1 << 10][2];
    int digitDP(string &s, int i = 0, int tight = 1, int used = 0, int lz = 1){
        if(i == s.size()) return 1;
        auto &_dp = dp[i][tight][used][lz];
        if(_dp != -1) return _dp;

        char limit = tight ? s[i] : '9';
        _dp = 0;

        for(int d = '0'; d <= limit; d++){
            if((used >> (d - '0')) & 1) continue;
            _dp += digitDP(
                s,                      
                i + 1, 
                tight && (d == limit),
                (d != '0' || !lz) ? used | (1 << (d - '0')) : used,
                lz && (d == '0')
            );
        }
        return _dp;
    }
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return n - digitDP(s) + 1; // +1 for 0...0 is counted as unique digit
    }
};
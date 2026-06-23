// Last updated: 6/24/2026, 3:32:03 AM
class Solution {
public:
    int dp[101][2][10][2], mod = 1e9 + 7;
    int digitDP(string &s, int i, int tight, char prev, int lz){
        if(i == s.size()) return 1;
        auto &_dp = dp[i][tight][prev - '0'][lz];
        if(_dp != -1) return _dp;
        _dp = 0;
    
        char limit = tight ? s[i] : '9';
    
        for(int d = '0'; d <= limit; d++){
            if(!lz && abs(d - prev) != 1) continue;
            _dp += digitDP(
                s,                      
                i + 1, 
                tight && (d == limit),
                d,
                lz && (d == '0')
            );
            _dp %= mod;
        }
        return _dp;
    }
    bool valid(string s){
        for(int i = 1; i < s.size(); i++){
            if(abs(s[i] - s[i - 1]) != 1) return false;
        }
        return true;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        int ans = digitDP(high, 0, 1, '0', 1);

        memset(dp, -1, sizeof(dp));
        ans = (mod + ans - digitDP(low, 0, 1, '0', 1)) % mod;

        if(valid(low)) ans = (ans + 1) % mod;

        return ans;
    }
};
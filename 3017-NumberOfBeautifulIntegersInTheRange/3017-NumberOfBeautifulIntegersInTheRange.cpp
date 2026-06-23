// Last updated: 6/24/2026, 3:31:59 AM
class Solution {
public:
    int dp[11][2][2][20][21];

    long long power(long long a,long long b, int mod){
        long long ans = 1;

        while(b){
            if(b & 1) ans = ans * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }
    int digitDP(string &s, int i, int tight, int lz, int rem, int diff, int k){
        if(i == s.size()) return !rem && !diff;
        auto &_dp = dp[i][tight][lz][rem][diff + 10];
        if(_dp != -1) return _dp;

        char limit = tight ? s[i] : '9';
        _dp = 0;

        for(int d = '0'; d <= limit; d++){
            int nlz = lz && (d == '0');
            _dp += digitDP(
                s,                      
                i + 1, 
                tight && (d == limit),  // tight for next
                nlz,        // inc count if digit is 1
                (rem + (d - '0') * power(10,s.size() - i - 1, k)) % k,
                diff + (((d - '0') & 1) - !((d - '0') & 1)) * !nlz,
                k
            );
        }
        return _dp;
    }
    int f(string s, int k){
        memset(dp, -1, sizeof(dp));
        return digitDP(s, 0, true, true, 0, 0, k);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return f(to_string(high), k) - f(to_string(low - 1), k);
    }
};
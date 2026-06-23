// Last updated: 6/24/2026, 3:31:35 AM
class Solution {
public:
    char max_digit;
    long long dp[16][2];
    long long digitDP(string &s, int i, int tight, string& suff){
        if(i == s.size()) return 1;
        auto &_dp = dp[i][tight];
        if(_dp != -1) return _dp;

        char limit = tight ? s[i] : '9';
        _dp = 0;
        if(suff[i] != '?'){
            if(suff[i] <= limit) _dp += digitDP(s, i + 1, tight && (suff[i] == limit), suff);
        }
        else {
            for(int d = '0'; d <= min(max_digit, limit); d++){
                _dp += digitDP(s, i + 1, tight && (d == limit), suff);
            }
        }
        return _dp;
    }
    long long numberOfPowerfulInt(long long l, long long r, int limit, string s) {
        max_digit = limit + '0';

        memset(dp, -1, sizeof(dp));
        string right = to_string(r);
        string suff = string(right.size() - s.size(), '?') + s;
        long long ans = digitDP(right, 0, 1, suff);
        // cout << "right : " << ans;

        memset(dp, -1, sizeof(dp));
        string left = to_string(l - 1);
        if(left.size() >= s.size()) {
            suff = string(left.size() - s.size(), '?') + s;
            ans -= digitDP(left, 0, 1, suff);
        }
        return ans;
    }
};
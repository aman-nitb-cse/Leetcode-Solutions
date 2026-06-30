// Last updated: 6/30/2026, 7:16:59 PM
using ll = long long;

    ll dp[20][2][2];

    ll digitDP(string &s, int i, int tight, int started){

        if(i == s.size()) return 1; // modify

        auto &_dp = dp[i][tight][started];

        if(_dp != -1) return _dp;

        _dp = 0;

        char limit = tight ? s[i] : '9';

        for(char d = '0'; d <= limit; d++){

            _dp += digitDP(
                s,
                i + 1,
                tight && (d == limit),
                started || d != '0'
            );
            
        }

        return _dp;
    }

    ll count(ll x){

        if(x < 0) return 0;

        string s = to_string(x);

        memset(dp, -1, sizeof(dp));

        return digitDP(s, 0, 1, 0);
    }
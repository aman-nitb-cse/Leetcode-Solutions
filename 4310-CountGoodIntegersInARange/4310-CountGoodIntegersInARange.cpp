// Last updated: 6/24/2026, 3:26:37 AM
class Solution {
public:
    using ll = long long;

    ll dp[20][2][11];
    int K;

    ll digitDP(string &s, int i, int tight, int prev){

        if(i == s.size()) return prev != 10;

        ll &_dp = dp[i][tight][prev];

        if(_dp != -1) return _dp;

        _dp = 0;

        char limit = tight ? s[i] : '9';

        for(char d = '0'; d <= limit; d++){

            int digit = d - '0';

            if(prev < 10 && abs(prev - digit) > K) continue;

            _dp += digitDP(
                s,
                i + 1,
                tight && (d == limit),
                (prev == 10 && digit == 0) ? 10 : digit
            );
        }

        return _dp;
    }

    ll count(ll x){

        if(x <= 0) return 0;

        string s = to_string(x);

        memset(dp, -1, sizeof(dp));

        return digitDP(s, 0, 1, 10);
    }

    ll goodIntegers(ll l, ll r, int k) {

        K = k;

        return count(r) - count(l - 1);
    }
};
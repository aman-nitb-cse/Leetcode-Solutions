// Last updated: 6/24/2026, 3:29:49 AM
class Solution {
public:
    long long dp[1700][2][12];
    const int MOD = 1e9 + 7;
    int b;

    long long digitDP(string &s, int i = 0, int tight = 1, int prev = 0){
        if(i == s.size()) return 1;

        auto &_dp = dp[i][tight][prev];
        if(_dp != -1) return _dp;

        int limit = tight ? (s[i] - '0') : (b - 1);
        _dp = 0;

        for(int d = prev; d <= limit; d++){
            _dp = (_dp + digitDP(
                s,
                i + 1,
                tight && (d == limit),
                d
            )) % MOD;
        }
        return _dp;
    }

    string convertBase(string s){
        if(s == "0") return "0";

        string ans = "";

        while(s != "0"){
            int rem = 0;
            string t = "";

            for(char c : s){
                int cur = rem * 10 + (c - '0');

                if(!t.empty() || cur / b != 0)
                    t += (cur / b) + '0';

                rem = cur % b;
            }

            ans += rem + '0';
            s = t.empty() ? "0" : t;
        }

        ranges::reverse(ans);
        return ans;
    }

    int countNumbers(string l, string r, int _b) {
        b = _b;
        r = convertBase(r);
        l = convertBase(l);

        memset(dp, -1, sizeof(dp));
        long long right = digitDP(r);

        memset(dp, -1, sizeof(dp));
        long long left = digitDP(l);

        long long ans = (right - left + MOD) % MOD;

        if(ranges::is_sorted(l)) ans = (ans + 1) % MOD;

        return ans;
    }
};
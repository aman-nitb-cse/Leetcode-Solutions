// Last updated: 11/6/2026, 4:49:40 AM
class Solution {
public:
    int k;
    int power(int a, int b) {
        int ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % k;

            a = a * a % k;
            b >>= 1;
        }

        return ans;
    }

    int dp[10][2][2][20][20];

    int digitDP(string& s, int i, int tight, int lz, int rem, int dif) {

        if (i == s.size())
            return dif == 0 && rem == 0 && !lz;

        int& ans = dp[i][tight][lz][rem][dif + 10];

        if (ans != -1)
            return ans;

        ans = 0;

        char limit = tight ? s[i] : '9';

        for (char c = '0'; c <= limit; c++) {
            int d = c - '0';

            int nlz = lz && (c == '0');
            int ndif = dif;

            if (!nlz) {
                if (d & 1)
                    ndif++;
                else
                    ndif--;
            }

            // cout << c << ' ' << nlz << endl;

            ans +=
                digitDP(s, i + 1, tight && (c == limit), nlz,
                        (rem + d * power(10, (int)s.size() - 1 - i)) % k, ndif);
        }
        // cout << ans << endl;

        return ans;
    }
    int cnt(int n) {
        memset(dp, -1, sizeof(dp));
        auto s = to_string(n);
        return digitDP(s, 0, 1, 1, 0, 0);
    }
    int numberOfBeautifulIntegers(int low, int high, int _k) {
        k = _k;
        return cnt(high) - cnt(low - 1);
    }
};
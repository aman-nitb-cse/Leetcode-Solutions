// Last updated: 6/25/2026, 11:09:55 PM
class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;

    vector<ll> pw;
    int dp[100001][2][3][2];

    int f(int n, int l, int e, int t){

        l = min(l, 1);
        e = min(e, 2);
        t = min(t, 1);

        if(l && t && e == 2) return pw[n];
        if(n == 0) return 0;

        int &ans = dp[n][l][e][t];
        if(ans != -1) return ans;

        ans = 0;

        ans += f(n - 1, 1, e, t);
        ans %= mod;

        ans += f(n - 1, l, min(e + 1, 2), t);
        ans %= mod;

        ans += f(n - 1, l, e, 1);
        ans %= mod;

        ans += (23LL * f(n - 1, l, e, t)) % mod;
        ans %= mod;

        return ans;
    }

    int stringCount(int n) {

        memset(dp, -1, sizeof(dp));

        pw.assign(n + 1, 1);

        for(int i = 1; i <= n; i++)
            pw[i] = pw[i - 1] * 26 % mod;

        return f(n, 0, 0, 0);
    }
};
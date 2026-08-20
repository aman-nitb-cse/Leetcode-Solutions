// Last updated: 8/20/2026, 8:27:16 PM
class Solution {
    vector<long long> fact, invFact;

public:
    const int mod = 1e9 + 7;
    using ll = long long;

    ll power(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    void precompute(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        
        fact[0] = 1;
        invFact[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        
        invFact[n] = power(fact[n], mod - 2);
        
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
        }
    }

    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        
        ll ans = fact[n];
        ans = (ans * invFact[n - r]) % mod;
        ans = (ans * invFact[r]) % mod;
        
        return ans;
    }

    int countValidSequences(int n, int k) {
        if (n < k) return 0;
        precompute(n);

        ll total = nCr(n - 1, k - 1);
        ll all_odd = 0;

        if (!((n - k) & 1)) {
            ll s = (n + k - 2) / 2;
            all_odd = nCr(s, k - 1);
        }

        return (total - all_odd + mod) % mod;
    }
};
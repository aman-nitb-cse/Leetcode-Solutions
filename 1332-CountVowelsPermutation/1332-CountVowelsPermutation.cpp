// Last updated: 6/25/2026, 11:17:39 PM
class Solution {
public:
    using ll = long long;
    int countVowelPermutation(int n) {
        ll a = 1, e = 1, i = 1, o = 1, u = 1;

        const int mod = 1e9 + 7;

        for(int k = 2; k <= n; k++){
            ll na = e;
            ll ne = a + i;
            ll ni = a + e + o + u;
            ll no = i + u;
            ll nu = a;

            a = na % mod;
            e = ne % mod;
            i = ni % mod;
            o = no % mod;
            u = nu % mod;
        }

        return (a + e + i + o + u) % mod;
    }
};
// Last updated: 7/26/2026, 9:25:50 AM
1class Solution {
2public:
3    int mod = 1e9 + 7;
4    using ll = long long;
5    ll power(ll a, ll b){
6        ll ans = 1;
7
8        while(b){
9            if(b & 1) ans = (ans * a) % mod;
10
11            a = (a * a) % mod;
12
13            b >>= 1;
14        }
15
16        return ans;
17    }
18    ll modInv(ll n){
19        return power(n, mod - 2);
20    }
21    ll nCr(ll n, ll r){
22        if(r < 0 || r > n) return 0;
23
24        if(r == 0 ||r == n) return 1;
25
26        r = min(r, n - r);
27
28        ll num  = 1;
29        ll d = 1;
30
31
32        for(int i = 0; i < r; i++){
33            num = (num * (n - i)) % mod;
34            d = (d * (i + 1)) % mod;
35        }
36
37        return (num * modInv(d)) % mod;
38    }
39    int countValidSequences(int n, int k) {
40        if(n < k) return 0;
41
42        ll t = nCr(n - 1, k - 1);
43        ll x = 0;
44
45        if(((n - k) &1) == 0){
46            ll s = (n + k - 2) / 2;
47            x = nCr(s, k - 1);
48        }
49
50        return (t - x + mod) % mod;
51    }
52};
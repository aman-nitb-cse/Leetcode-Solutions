// Last updated: 8/20/2026, 8:45:38 PM
class Solution {
public:
    using ll = long long;

    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        ll k = 1LL * k1 + k2;
        int n = a.size();

        for(int i = 0; i < n; i++) a[i] = abs(a[i] - b[i]);

        ranges::sort(a);

        vector<ll> suf(n);

        for(int i = n - 1; i >= 0; i--){
            suf[i] = a[i];
            if(i + 1 < n) suf[i] += suf[i + 1];
        }

        int s = 0, e = a.back();

        while(s < e){
            int mid = (s + e) >> 1;

            int nxt = ranges::upper_bound(a, mid) - a.begin();

            ll need = 0;

            if(nxt < n) need = suf[nxt] - 1LL * (n - nxt) * mid;

            if(need > k) s = mid + 1;
            else e = mid;
        }

        ll left = k;

        int nxt = ranges::upper_bound(a, s) - a.begin();

        if(nxt < n) left -= suf[nxt] - 1LL * (n - nxt) * s;

        for(int &x : a){
            if(x > s) x = s;

            if(left && x == s && x){
                x--;
                left--;
            }
        }

        ll ans = 0;

        for(int &x : a) ans += 1LL * x * x;

        return ans;
    }
};
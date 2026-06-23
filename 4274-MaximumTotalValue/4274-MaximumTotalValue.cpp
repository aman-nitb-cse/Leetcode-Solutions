// Last updated: 6/24/2026, 3:27:14 AM
class Solution {
public:
    int mod = 1e9 + 7;
    using ll = long long;
    int maxTotalValue(vector<int>& v, vector<int>& d, int m) {

        ll pos = 0, all = 0;

        for(int i = 0; i < v.size(); i++){
            ll c = (v[i] - 1) / d[i] + 1;

            pos += c;

            ll last = v[i] - 1LL * (c - 1) * d[i];

            ll sum = c * (1LL * v[i] + last) / 2;

            all = (all + sum % mod) % mod;
        }

        if(pos <= m) return all;
        
        int s = 1, e = 1e9, T = 1;

        while(s <= e){
            int mid = (s + e) >> 1;

            // count 
            int cnt = 0;
            for(int i = 0; i < v.size(); i++){
                if(v[i] < mid) continue;

                cnt += (v[i] - mid) / d[i] + 1;

                if(cnt >= m) break;
            }

            if(cnt >= m){
                T = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }

        ll ans = 0, cnt = 0;

        for(int i = 0; i < v.size(); i++){
            
            if(v[i] <= T) continue;

            ll c = (v[i] - T - 1) / d[i] + 1;

            cnt += c;

            ll last = v[i] - 1LL * (c - 1) * d[i];

            ll sum = c * (1LL * v[i] + last) / 2;

            ans = (ans + sum) % mod;

            // debug
            // cout << ans << ' ';
        }

        ll need = m - cnt;
        ans = (ans + (need % mod) * (T % mod)) % mod;
        return ans;
    }
};

















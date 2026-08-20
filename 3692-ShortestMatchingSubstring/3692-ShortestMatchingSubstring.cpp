// Last updated: 8/20/2026, 8:38:06 PM
class Solution {
public:
    using ll = unsigned long long;
    ll BASE = 131;

    int shortestMatchingSubstring(string s, string p) {
        ll h = 0;
        int sz = 0;

        int n = s.size();

        ll left = 0, mid = 0, right = 0;
        int l = 0, m = 0, r = 0;
        int star = 0;

        for(char &c : p){
            if(c == '*'){
                if(star == 0) {
                    left = h;
                    l = sz;
                }
                else if(star == 1) {
                    mid = h;
                    m = sz;
                }
                h = 0;
                sz = 0;
                star++;
            }
            else {
                h = h * BASE + c;
                sz++;
            }
        }

        right = h;
        r = sz;

        /// build power
        vector<ll> pw(n + 1,1);
        for(int i = 0; i < n; i++) pw[i + 1] = pw[i] * BASE;



        // sliding window
        vector<int> L, M, R;

        // for left
        h = 0;
        for(int i = 0; i < l; i++){
            h = h * BASE + s[i];
        }
        if(h == left) L.push_back(0);

        for(int i = l; i < n; i++){
            h = h * BASE + s[i];
            h -= pw[l] * s[i - l];
            if(h == left) L.push_back(i - l + 1);
        }

        // mid
        h = 0;
        for(int i = 0; i < m; i++){
            h = h * BASE + s[i];
        }
        if(h == mid) M.push_back(0);

        for(int i = m; i < n; i++){
            h = h * BASE + s[i];
            h -= pw[m] * s[i - m];
            if(h == mid) M.push_back(i - m + 1);
        }

        // right
        h = 0;
        for(int i = 0; i < r; i++){
            h = h * BASE + s[i];
        }
        if(h == right) R.push_back(0);

        for(int i = r; i < n; i++){
            h = h * BASE + s[i];
            h -= pw[r] * s[i - r];
            if(h == right) R.push_back(i - r + 1);
        }

        int ans = INT_MAX;

        if(l == 0) for(int i = 0; i < n; i++) L.push_back(i);
        if(m == 0) for(int i = 0; i < n; i++) M.push_back(i);
        if(r == 0) for(int i = 0; i < n; i++) R.push_back(i);

        for(int &i : M){
            int u = justLeft(L, i - l);
            int v = justRight(R, i + m);

            if(u >= 0 && v >= 0) {
                ans = min(ans, v + r - u);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
private:

    int justLeft(vector<int>& v, int i){ // <=
        auto it = ranges::upper_bound(v, i);
        if(it == v.begin()) return -1;
        return *prev(it);
    }
    int justRight(vector<int>& v, int i){ // >=
        auto it = ranges::lower_bound(v, i);
        if(it == v.end()) return -1;
        return *it;
    }
};
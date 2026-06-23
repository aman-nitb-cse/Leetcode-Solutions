// Last updated: 6/24/2026, 3:30:29 AM
class Solution {
public:

    using ull = unsigned long long;

    const ull b = 131;

    unordered_set<ull> st;

    vector<ull> h, p;

    int mx = 0;

    void buildPrefixes(vector<string>& w){

        for(auto &s : w){

            ull cur = 0;

            for(char &c : s){

                cur = cur * b + c;

                st.insert(cur);
            }

            mx = max(mx, (int)s.size());
        }
    }

    void buildHash(string &t){

        int n = t.size();

        h.resize(n + 1);

        p.resize(n + 1, 1);

        for(int i = 0; i < n; i++){

            h[i + 1] = h[i] * b + t[i];

            p[i + 1] = p[i] * b;
        }
    }

    ull get(int l, int len){

        return h[l + len] - h[l] * p[len];
    }

    int longest(int i, int n){

        int lo = 0, hi = min(mx, n - i);

        while(lo < hi){

            int mid = (lo + hi + 1) / 2;

            if(st.count(get(i, mid))) lo = mid;

            else hi = mid - 1;
        }

        return i + lo;
    }

    int jump(vector<int>& r){

        int ans = 0, cur = 0, far = 0, n = r.size();

        for(int i = 0; i < n; i++){

            far = max(far, r[i]);

            if(i == cur){

                if(far == i) return -1;

                ans++;

                cur = far;

                if(cur >= n) break;
            }
        }

        return ans;
    }

    int minValidStrings(vector<string>& w, string t) {

        int n = t.size();

        buildPrefixes(w);

        buildHash(t);

        vector<int> r(n);

        for(int i = 0; i < n; i++){

            r[i] = longest(i, n);
        }

        return jump(r);
    }
};
// Last updated: 11/6/2026, 5:02:34 AM
class Solution {
public:
    using ull = unsigned long long;
    const ull base = 1e6 + 3;
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        ull h = 0, pw = 1;
        for(int i = 0; i < k; i++){
            h = h * base + s[i];
            pw *= base;
        }

        unordered_set<ull> st;
        st.insert(h);
        for(int i = k; i < n; i++){
            h = h * base + s[i];
            h -= pw * s[i - k];
            st.insert(h);
        }

        return st.size() == (1 << k);
    }
};
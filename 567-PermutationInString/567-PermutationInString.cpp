// Last updated: 8/20/2026, 9:02:51 PM
class Solution {
public:
    bool checkInclusion(string s, string str) {
        unordered_multiset<char> hash;
        for (char& c : s)
            hash.insert(c);

        int m = s.size(), n = str.size();
        if (m > n)
            return false;
        unordered_multiset<char> st;
        for (int i = 0; i < m; i++)
            st.insert(str[i]);
        for (int i = 0; i <= n - m; i++) {
            if (i) {
                st.erase(st.find(str[i - 1]));
                st.insert(str[i + m - 1]);
            }
            if (st == hash)
                return true;
        }
        return false;
    }
};
// Last updated: 8/20/2026, 9:05:52 PM
class Solution {
public:
    vector<int> findAnagrams(string str, string s) {
        unordered_multiset<char> hash;
        vector<int> ans;
        for (char& c : s)
            hash.insert(c);

        int m = s.size(), n = str.size();
        if (m > n)
            return {};
        unordered_multiset<char> st;
        for (int i = 0; i < m; i++)
            st.insert(str[i]);
        for (int i = 0; i <= n - m; i++) {
            if (i) {
                st.erase(st.find(str[i - 1]));
                st.insert(str[i + m - 1]);
            }
            if (st == hash)
                ans.push_back(i);
        }
        return ans;
    }
};
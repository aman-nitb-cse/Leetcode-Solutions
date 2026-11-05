// Last updated: 11/6/2026, 4:49:09 AM
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for (int m = k; m <= s.length(); m++) {
            string ans = "";
            for (int i = m; i <= s.length(); i++) {
                string t = s.substr(i - m, m);
                if ((ans.empty() || t < ans) && ranges::count(t, '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
        return "";
    }
};
// Last updated: 8/20/2026, 9:15:50 PM
class Solution {
public:
    vector<string> ans;
    void bt(string &s, int i = 0, int dots = 3){
        if(dots == 0){
            auto st = s.substr(i);
            if(st.size() > 3 || st.empty() || (st[0] == '0' && st.size() > 1) || (st.size() == 3 && st > "255")) return;
            ans.push_back(s);
            return;
        }
        if(i >= s.size() - 1 || dots < 0) return;

        // put dot after i
        s.insert(s.begin() + i + 1, '.');
        bt(s, i + 2, dots - 1);
        s.erase(s.begin() + i + 1);

        if(i + 2 == s.size() || s[i] == '0') return;
        // put dot after i
        s.insert(s.begin() + i + 2, '.');
        bt(s, i + 3, dots - 1);
        s.erase(s.begin() + i + 2);

        if(i + 2 == s.size() || s.substr(i, 3) > "255") return;
        // put dot after i
        s.insert(s.begin() + i + 3, '.');
        bt(s, i + 4, dots - 1);
        s.erase(s.begin() + i + 3);
    }
    vector<string> restoreIpAddresses(string s) {
        bt(s);
        return ans;
    }
};
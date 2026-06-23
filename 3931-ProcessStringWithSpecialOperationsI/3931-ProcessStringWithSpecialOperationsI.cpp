// Last updated: 6/24/2026, 3:29:36 AM
class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for(char &c : s){
            if(c == '*' && !ans.empty()) ans.pop_back();
            else if(c == '#') ans += ans;
            else if(c == '%') ranges::reverse(ans);
            else if(c <= 'z' && c >= 'a') ans.push_back(c);
        }

        return ans;
    }
};
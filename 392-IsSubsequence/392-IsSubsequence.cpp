// Last updated: 8/20/2026, 9:07:00 PM
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;
        int i = 0;
        for(char &c : t){
            if(c == s[i]) i++;
        }
        return i == s.size();
    }
};
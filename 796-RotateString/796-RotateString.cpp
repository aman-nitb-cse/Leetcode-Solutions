// Last updated: 11/6/2026, 5:12:51 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int t = s.size();
        while(t--){
            if(s == goal) return true;
            s += s[0];
            s.erase(0, 1);
        }
        return false;
    }
};
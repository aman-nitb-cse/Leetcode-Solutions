// Last updated: 6/25/2026, 11:20:59 PM
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
// Last updated: 11/6/2026, 4:33:04 AM
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < s.size(); i++){
            if(abs(s[i] - s[i - 1]) > 2) return false;
        }
        return true;
    }
};
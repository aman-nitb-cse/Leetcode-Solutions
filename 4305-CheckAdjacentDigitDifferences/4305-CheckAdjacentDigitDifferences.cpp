// Last updated: 6/24/2026, 3:26:41 AM
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < s.size(); i++){
            if(abs(s[i] - s[i - 1]) > 2) return false;
        }
        return true;
    }
};
// Last updated: 6/24/2026, 3:29:48 AM
class Solution {
public:
    int reverseDegree(string s) {
        int deg = 0;
        for(int i = 0; i < s.size(); i++){
            deg += (i + 1) * ('z' - s[i] + 1);
        }
        return deg;
    }
};
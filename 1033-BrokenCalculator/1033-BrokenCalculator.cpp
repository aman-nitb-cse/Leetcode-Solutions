// Last updated: 6/25/2026, 11:19:08 PM
class Solution {
public:
    int brokenCalc(int s, int e) {
        if(s >= e) return s - e;
        if(e & 1) return 1 + brokenCalc(s, e + 1);
        return 1 + brokenCalc(s, e / 2);
    }
};
// Last updated: 11/6/2026, 5:09:36 AM
class Solution {
public:
    int brokenCalc(int s, int e) {
        if(s >= e) return s - e;
        if(e & 1) return 1 + brokenCalc(s, e + 1);
        return 1 + brokenCalc(s, e / 2);
    }
};
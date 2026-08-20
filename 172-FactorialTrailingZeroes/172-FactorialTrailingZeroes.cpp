// Last updated: 8/20/2026, 9:12:32 PM
class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0) return 0;
        return n / 5 + trailingZeroes(n / 5);
    }
};
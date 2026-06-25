// Last updated: 6/25/2026, 11:16:58 PM
class Solution {
public:
    int numberOfSteps(int n) {
        // base
        if(n == 0) return 0;

        // odd
        if(n&1) return 1 + numberOfSteps(n - 1);

        // even
        return 1 + numberOfSteps(n >> 1);
    }
};
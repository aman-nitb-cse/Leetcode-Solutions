// Last updated: 11/6/2026, 5:04:43 AM
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
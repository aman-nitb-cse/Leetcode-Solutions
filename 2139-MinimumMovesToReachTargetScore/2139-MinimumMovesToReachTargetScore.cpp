// Last updated: 11/6/2026, 5:06:28 AM
class Solution {
public:
    int minMoves(int n, int d) {
        // base case
        if(n == 1) return 0;

        // no double available
        if(d == 0) return n - 1;

        // odd
        if(n & 1) return 1 + minMoves(n - 1, d);

        // even
        return 1 + minMoves(n / 2, d - 1);
    }
};
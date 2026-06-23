// Last updated: 6/24/2026, 3:29:08 AM
class Solution {
public:
    int minCost(int n) {
        n--;
        return n * (n + 1) / 2;
    }
};
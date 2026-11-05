// Last updated: 11/6/2026, 4:40:07 AM
class Solution {
public:
    int minCost(int n) {
        n--;
        return n * (n + 1) / 2;
    }
};
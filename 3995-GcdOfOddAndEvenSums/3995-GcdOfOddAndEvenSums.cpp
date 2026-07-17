// Last updated: 7/18/2026, 12:22:04 AM
class Solution {
public:
    int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
    int gcdOfOddEvenSums(int n) { return gcd(n * n, n * (n + 1)); }
};
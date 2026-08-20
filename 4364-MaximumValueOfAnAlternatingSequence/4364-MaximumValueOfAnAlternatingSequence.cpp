// Last updated: 8/20/2026, 8:26:47 PM
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // /\/\

        int inc = n / 2;

        return s + 1LL * inc * (m) - max(inc - 1, 0);
    }
};

// 1 2 3 4
// Last updated: 7/18/2026, 8:12:09 PM
1class Solution {
2public:
3    long long maximumValue(int n, int s, int m) {
4        // /\/\
5
6        int inc = n / 2;
7
8        return s + 1LL * inc * (m) - max(inc - 1, 0);
9    }
10};
11
12// 1 2 3 4
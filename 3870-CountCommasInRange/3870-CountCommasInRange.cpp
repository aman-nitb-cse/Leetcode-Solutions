// Last updated: 11/6/2026, 4:35:37 AM
class Solution {
public:
    int countCommas(int n) {
        int res = 0;
        for (int a = 1; a <= n; ++a) {
            if (a > 999) {
                res += 1;
            }
        }
        return res;
    }
};
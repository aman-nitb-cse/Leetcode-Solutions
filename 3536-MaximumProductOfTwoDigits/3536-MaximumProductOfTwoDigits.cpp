// Last updated: 11/6/2026, 4:42:07 AM
class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while (n > 0) {
            int x = n % 10;
            if (x > first) {
                second = first;
                first = x;
            } else if (x > second) {
                second = x;
            }
            n /= 10;
        }
        return first * second;
    }
};
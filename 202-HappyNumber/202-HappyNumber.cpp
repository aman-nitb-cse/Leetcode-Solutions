// Last updated: 8/20/2026, 9:11:56 PM
class Solution {
public:
    int sq(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = sq(n);
        while(slow != fast) {
            slow = sq(slow);
            fast = sq(sq(fast));
        }
        if (slow == 1) return 1;
        return 0;
    }
};
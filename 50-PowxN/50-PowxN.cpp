// Last updated: 8/20/2026, 9:17:56 PM
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 or x == 1) return 1;
        if(n == 1) return x;
        if(n < 0){
            x = 1 / x;
            return myPow(x * x, -(n / 2)) * myPow(x, n & 1);
        }
        return myPow(x * x, n / 2) * myPow(x, n & 1);
    }
};
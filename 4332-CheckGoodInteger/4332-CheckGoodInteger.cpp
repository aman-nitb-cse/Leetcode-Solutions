// Last updated: 6/24/2026, 3:26:25 AM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int x;
        while(n){
            int d = n % 10;
            x += d * d;
            x -= d;

            n /= 10;
        }

        return x >= 50;
    }
};
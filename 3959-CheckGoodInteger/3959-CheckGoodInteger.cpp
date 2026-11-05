// Last updated: 11/6/2026, 4:32:23 AM
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
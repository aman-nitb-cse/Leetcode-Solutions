// Last updated: 6/24/2026, 3:26:38 AM
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        while(n){
            if((n & 3) == 3) {
                cnt++;
            }
            n >>= 1;
        }
        return cnt == 1;
    }
};
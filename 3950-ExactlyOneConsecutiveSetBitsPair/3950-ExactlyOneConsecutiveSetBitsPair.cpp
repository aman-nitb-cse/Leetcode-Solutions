// Last updated: 11/6/2026, 4:32:58 AM
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
// Last updated: 8/20/2026, 9:12:14 PM
class Solution {
public:
    int reverseBits(int n) {
        int sum = 0, j = 31;
        while(n){
            sum += (1 << j--) * (n&1);
            n = n >> 1;
        }
        return sum;
    }
};
// Last updated: 8/20/2026, 9:12:11 PM
class Solution {
public:
    int hammingWeight(int n) {
        int sum = 0;
        while(n){
            sum += (n&1);
            n >>= 1;
        }
        return sum;
    }
};
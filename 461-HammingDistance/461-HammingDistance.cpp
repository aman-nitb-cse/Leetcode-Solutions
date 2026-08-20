// Last updated: 8/20/2026, 9:05:01 PM
class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int count = 0;
        while(x){
            count += (x & 1);
            x >>= 1;
        }
        return count;
    }
};
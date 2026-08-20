// Last updated: 8/20/2026, 9:10:45 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        int count = 0;
        while(n){
            count += n&1;
            if(count == 2) return false;
            n >>= 1;
        }
        return true;
    }
};
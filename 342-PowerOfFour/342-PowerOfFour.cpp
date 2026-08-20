// Last updated: 8/20/2026, 9:08:18 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n) return false;
        while(n){
            if(n%4 and n != 1) return false;
            n /= 4;
        }
        return true;
    }
};
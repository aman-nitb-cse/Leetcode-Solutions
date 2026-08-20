// Last updated: 8/20/2026, 9:08:44 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) return false;
        while(n){
            if(n%3 and n != 1) return false;
            n /= 3;
        }
        return true;
    }
};
// Last updated: 11/6/2026, 4:59:11 AM
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            if(n%3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
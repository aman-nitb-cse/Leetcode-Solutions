// Last updated: 6/25/2026, 11:14:52 PM
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
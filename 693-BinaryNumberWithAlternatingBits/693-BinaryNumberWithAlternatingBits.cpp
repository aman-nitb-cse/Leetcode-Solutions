// Last updated: 6/25/2026, 11:37:10 PM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1; n >>= 1;
        while(n){
            int curr = n & 1; n >>= 1;
            if(prev == curr) return false;
            prev = curr;
        }
        return true;
    }
};
// Last updated: 11/6/2026, 5:09:08 AM
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1 ;
        int mask = n ;
        int i = 0 ;
        while(mask){
            mask = mask >> 1 ;
            i++ ;
        }

        mask = exp2(i) - 1 ;
        return (n ^ mask) ;
    }
};
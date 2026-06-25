// Last updated: 6/25/2026, 11:18:55 PM
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
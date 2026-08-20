// Last updated: 8/20/2026, 9:20:45 PM
class Solution {
public:
    int reverse(int x) {
    if(x >= pow(2 , 31) || x < -pow(2 , 31)){
        return 0 ;
    } 
    int i = 0;
    while(x != 0){

        if(i > INT_MAX / 10 || (i == INT_MAX / 10 && i%10 > 7)) return 0 ;
        if(i < INT_MIN / 10 || (i == INT_MIN / 10 && i%10 < -8)) return 0 ; 
        i = (i*10) + (x%10) ;
        x /= 10 ;
    }
    return i ;
    }
};
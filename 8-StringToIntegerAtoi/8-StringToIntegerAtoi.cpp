// Last updated: 8/20/2026, 9:20:15 PM
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size() - 1 , i ;
        int sign = 1 ;
        bool key = true ;
        long long num = 0 ;
        for(i = 0 ; i <= size ; i++){
            if(s[i] == '+' and key) {
                key = false ;
                continue ;
            }    
            else if(s[i] == ' ' and key) continue ;
            else if(s[i] == '-' and key){
                key = false ;
                sign = -1 ;
                continue ;
            }
            else if(s[i] <= '9' and s[i] >= '0'){
                key = false ;
                num = 10 * num + (s[i] - '0') ;
                if(num * sign > INT_MAX) return INT_MAX ;
                else if(num * sign < INT_MIN) return INT_MIN ;
            }
            else break ;
        }
        return sign * num ;
    }
};
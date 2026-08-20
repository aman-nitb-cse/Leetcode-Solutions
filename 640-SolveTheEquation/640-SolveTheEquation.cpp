// Last updated: 8/20/2026, 9:01:59 PM
class Solution {
public: 
    // ax + b = 0;
    string solveEquation(string s) {
        int temp = 0;
        int a = 0, b = 0;
        int sign = 1; 
        int prev_sign = 1;
        char prev_char = 0;

        for(char &c : s){
            if(c <= '9' && c >= '0') temp = 10 * temp + (c - '0');
            else if(c == '+' || c == '-'){
                b += sign * prev_sign * temp;
                temp = 0;
                if(c == '-') prev_sign = -1;
                else prev_sign = 1;
            }
            else if(c == 'x'){
                if(temp == 0 && prev_char != '0') temp = 1;
                a += sign * prev_sign * temp;
                temp = 0;
                prev_sign = 1;
            }
            else if(c == '=') {
                b += sign * prev_sign * temp;
                temp = 0;
                sign = -1;
                prev_sign = 1;
            }
            prev_char = c;
        }
        b += sign * prev_sign * temp;
        
        if(a == 0) return b ? "No solution" : "Infinite solutions";
        return "x=" + to_string(-b/a);
    }
};
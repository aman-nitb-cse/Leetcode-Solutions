// Last updated: 6/25/2026, 11:18:48 PM
class Solution {
public:
    string baseNeg2(int n) {
        if(!n) return "0";
        string s = "";
        while(n){
            int c = ((n % 2) + 2) % 2;
            s.insert(s.begin(), c + '0');
            if(n < 0 and n % 2){
                n = n / (-2) + 1; 
            }
            else n /= -2;
        }
        return s;
    }
};
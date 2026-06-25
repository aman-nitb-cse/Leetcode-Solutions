// Last updated: 6/25/2026, 11:15:50 PM
class Solution {
public:
    string thousandSeparator(int n) {
        if(!n) return "0";
        string s = "";
        int i = 0;
        while(n){
            if(!(i%3) and i) s.insert(s.begin(), '.');
            s.insert(s.begin(), n%10 + '0');
            i++;
            n /= 10;
        }
        return s;
    }
};
// Last updated: 11/6/2026, 5:01:40 AM
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
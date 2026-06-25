// Last updated: 6/25/2026, 11:15:38 PM
class Solution {
public:
    char next(char c){
        return c == 'z' ? 'a' : c + 1;
    }
    char getChar(char a, char b){
        if(a == ' ') {
            if(b == '?' || b == ' ') return 'a';
            return next(b);
        }
        return b != next(a) ? next(a) : next(b);
    }
    string modifyString(string s) {
        s = ' ' + s + ' ';
        for(int i = 1; i < s.size() - 1; i++){
            if(s[i] != '?') continue;
            s[i] = getChar(s[i - 1], s[i + 1]);
        }
        return s.substr(1, s.size() - 2);
    }
};
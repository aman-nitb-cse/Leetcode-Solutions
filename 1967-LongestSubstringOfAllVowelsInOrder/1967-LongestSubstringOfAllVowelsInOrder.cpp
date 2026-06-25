// Last updated: 6/25/2026, 11:14:31 PM
class Solution {
public:
    char next(char c){
        if(c == 'a') return 'e';
        if(c == 'e') return 'i';
        if(c == 'i') return 'o';
        if(c == 'o') return 'u';
        return '\0';
    }
    int longestBeautifulSubstring(string s) {
        int maxi = 0, count = 0;
        for(int i = 0; i < s.size(); i++){
            if(count == 0){
                if(s[i] == 'a') count++;
                continue;
            }

            if(s[i - 1] == s[i] || next(s[i - 1]) == s[i]) count++;
            else if(s[i - 1] == 'u') {
                maxi = max(maxi, count);
                count = (s[i] == 'a');
            }
            else count = (s[i] == 'a');
        }
        if(s.back() == 'u') maxi = max(maxi, count);
        return maxi;
    }
};
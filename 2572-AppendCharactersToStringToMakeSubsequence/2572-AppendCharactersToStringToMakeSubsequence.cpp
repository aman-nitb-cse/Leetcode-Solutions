// Last updated: 6/25/2026, 11:11:15 PM
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        for(char &c : s){
            if(c == t[i]) i++;
        }
        return t.size() - i;
    }
};
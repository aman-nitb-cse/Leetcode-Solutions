// Last updated: 8/20/2026, 9:17:31 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        bool found = false;
        for(int i = s.size() - 1; i >= 0; i--){

            if(s[i] != ' '){
                found = true;
                if(!l) l = i; // index of last char
            }

            else {
                if(found) return l - i;
            }
        }
        return l + 1;
    }
};
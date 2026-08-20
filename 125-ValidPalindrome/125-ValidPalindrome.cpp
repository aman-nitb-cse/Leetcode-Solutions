// Last updated: 8/20/2026, 9:14:10 PM
class Solution {
public:
    bool isPalindrome(string str) {
        int s = 0, e = str.size() - 1;
        while(s < e){
            char c1 = tolower(str[s]);
            char c2 = tolower(str[e]);
            if(!isalnum(c1)){
                s++;
                continue;
            }
            if(!isalnum(c2)){
                e--;
                continue;
            }
            if(c1 != c2) return false;
            s++;
            e--;
        }
        return true;
    }
};
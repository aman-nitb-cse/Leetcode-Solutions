// Last updated: 11/6/2026, 4:46:24 AM
class Solution {
public:
    int numberOfSpecialChars(string s) {
        int cnt = 0;
        for(char l = 'a', u = 'A'; l <= 'z'; l++, u++){
            bool u_found = false, l_found = false, valid = true;
            for(char &c : s){
                if(c == l){
                    if(u_found){
                        valid = false;
                        break;
                    }
                    l_found = true;
                }
                else if(c == u) u_found = true;
            }

            if(valid && u_found && l_found) cnt++;
        }

        return cnt;
    }
};
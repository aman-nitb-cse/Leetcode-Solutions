// Last updated: 6/25/2026, 11:37:21 PM
class Solution {
public:
    bool validPalindrome(string str) {
        bool flag = true; // can skip char
        int s = 0, e = str.size() - 1;
        while(s < e){
            if(str[e] != str[s]){
                if(flag){
                    if(str[s + 1] == str[e] and str[e - 1] == str[s]){
                        return validPalindrome(str.substr(s + 1, e - s - 1)) or validPalindrome(str.substr(s, e - s - 1));
                    }
                    else if(str[s + 1] == str[e]){ s++; flag = false;}
                    else if(str[e - 1] == str[s]) { e--; flag = false;}
                    else return false;
                }
                else return false;
            }
            else {
                s++; 
                e--;
            }
        }
        return true;
    }
};
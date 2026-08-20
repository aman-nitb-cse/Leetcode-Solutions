// Last updated: 8/20/2026, 9:20:09 PM
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);


        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i]) return false;
        }

        return true;
    }
};
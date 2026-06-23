// Last updated: 6/24/2026, 3:28:11 AM
class Solution {
public:
    string reverseByType(string s) {
        // if(s == "")
        string special = "";
        string lower = "";
        for(char &c : s){
            if(isalnum(c)) lower += c;
            else special += c;
        }

        int i = special.size() - 1, j = lower.size() - 1;

        for(char &c : s){
            if(isalnum(c)) c = lower[j--];
            else c = special[i--];
        }
        return s;
    }
};
// Last updated: 6/25/2026, 11:15:03 PM
class Solution {
public:
    int minimumLength(string s) {
        char c = 0;
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i] == c) i++;
            else if(s[j] == c) j--;
            else if(s[i] == s[j] && i ^ j) c = s[i];
            else break;
        }
        return j - i + 1;
    }
};
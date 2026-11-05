// Last updated: 11/6/2026, 4:59:35 AM
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
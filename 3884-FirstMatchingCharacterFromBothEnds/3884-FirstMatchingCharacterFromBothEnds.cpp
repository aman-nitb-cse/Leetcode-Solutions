// Last updated: 11/6/2026, 4:34:53 AM
class Solution {
public:
    int firstMatchingIndex(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i] == s[j]) return i;
            i++;
            j--;
        }
        return -1;
    }
};
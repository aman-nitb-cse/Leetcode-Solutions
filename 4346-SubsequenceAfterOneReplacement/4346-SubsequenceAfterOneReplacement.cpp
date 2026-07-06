// Last updated: 7/6/2026, 5:33:55 AM
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i = 0, j = 0, n = s.size();

        // i -> no replacement
        // j -> single replacement
        
        for(char &c : t){

            j = max(j + (s[j] == c), i + 1);

            i += (s[i] == c);

            if(max(i, j) == n) return true;
        }

        return false;
    }
};
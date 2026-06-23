// Last updated: 6/24/2026, 3:29:10 AM
class Solution {
public:
    string mergeCharacters(string &s, int k) {
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size() && j - i <= k; j++){
                if(s[i] == s[j]) {
                    s.erase(j, 1);
                    return mergeCharacters(s, k);
                }
            }
        }
        return s;
    }
};
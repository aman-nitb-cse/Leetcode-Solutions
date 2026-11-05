// Last updated: 11/6/2026, 4:40:12 AM
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
// Last updated: 8/20/2026, 9:19:50 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        for(int i = 0; i < s[0].size(); i++){ // represent index
            char c = s[0][i];
            for(int j = 0; j < s.size(); j++){
                if(i == s[j].size()) return s[j];
                if(s[j][i] != c) return s[0].substr(0, i);
            }
        }
        return s[0];
    }
};
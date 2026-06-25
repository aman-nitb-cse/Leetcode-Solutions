// Last updated: 6/25/2026, 11:21:15 PM
class Solution {
public:
    vector<string> ans;
    void bt(string &s, int i = 0){
        if(i == s.size()){
            ans.push_back(s);
            return;
        }

        if(s[i] <= '9' && s[i] >= '0') {
            bt(s, i + 1);
            return;
        }

        s[i] = tolower(s[i]);
        bt(s, i + 1);
        s[i] = toupper(s[i]);
        bt(s, i + 1);
    }
    vector<string> letterCasePermutation(string s) {
        bt(s);
        return ans;
    }
};
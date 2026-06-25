// Last updated: 6/25/2026, 11:12:27 PM
class Solution {
public:
    string largestGoodInteger(string s) {
        string ans = "";
        for(int i = 0; i < s.size() - 2; i++){
            if(s[i] == s[i + 1] && s[i] == s[i + 2] && (ans == "" || ans[0] < s[i])){
                ans = string(3, s[i]);
            }
        }
        return ans;
    }
};
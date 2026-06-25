// Last updated: 6/25/2026, 11:18:44 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(char &i : s){
            if(count) ans += i;
            if(i == '(') count++;
            else count--;

            if(!count and !ans.empty()) ans.pop_back();
        }
        return ans;
    }
};
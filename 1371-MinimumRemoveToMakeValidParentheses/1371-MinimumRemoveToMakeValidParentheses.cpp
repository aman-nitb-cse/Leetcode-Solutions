// Last updated: 6/25/2026, 11:17:28 PM
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++){
            if('(' == s[i]) st.push({'(', i});
            else if(')' == s[i]){
                if(st.empty() || st.top().first != '(') st.push({')', i});
                else st.pop();
            }
        }
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--){
            if(!st.empty() && st.top().second == i){
                st.pop();
                continue;
            }
            ans += s[i];
        }
        ranges::reverse(ans);
        return ans;
    }
};
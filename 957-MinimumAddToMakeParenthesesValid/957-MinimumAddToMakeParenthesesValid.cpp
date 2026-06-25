// Last updated: 6/25/2026, 11:19:47 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char &c : s){
            if(!st.empty() && ')' == c && '(' == st.top()) st.pop();
            else st.push(c);
        }
        return st.size();
    }
};
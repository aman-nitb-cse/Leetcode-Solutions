// Last updated: 6/25/2026, 11:11:51 PM
class Solution {
public:
    string removeStars(string s) {
        stack<int> st;

        for(char &c : s){
            if(c == '*') st.pop();
            else st.push(c);
        }

        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        ranges::reverse(s);
        return s;
    }
};
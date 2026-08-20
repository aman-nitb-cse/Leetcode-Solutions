// Last updated: 8/20/2026, 9:19:35 PM
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char &i : s){
            if(i == '(' || i == '{' || i == '[') st.push(i);
            else if(st.empty()) return false;
            else if(i == ')' and st.top() == '(') st.pop();
            else if(i == ']' and st.top() == '[') st.pop();
            else if(i == '}' and st.top() == '{') st.pop();
            else return false;
        }
        return st.empty();
    }
};
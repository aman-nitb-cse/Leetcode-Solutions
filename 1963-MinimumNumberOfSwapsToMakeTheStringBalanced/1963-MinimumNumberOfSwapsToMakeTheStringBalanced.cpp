// Last updated: 11/6/2026, 4:56:38 AM
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(char &c : s){
            if(!st.empty() && '[' == st.top() && ']' == c) st.pop();
            else st.push(c);
        }
        return (st.size() + 2) / 4;
    }
};
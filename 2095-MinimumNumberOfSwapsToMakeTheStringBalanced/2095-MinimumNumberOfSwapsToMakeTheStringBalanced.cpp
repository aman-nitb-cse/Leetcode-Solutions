// Last updated: 6/25/2026, 11:13:53 PM
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
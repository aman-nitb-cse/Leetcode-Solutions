// Last updated: 8/20/2026, 9:06:57 PM
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(char &i : s){
            if(i != ']') st.push(i);
            else {
                // calculate string under box
                string temp = "";
                while(st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                // remove '['
                st.pop();

                // calculate k
                string num = "";
                while(!st.empty() && st.top() <= '9' && st.top() >= '0'){
                    num += st.top();
                    st.pop();
                }
                ranges::reverse(num);
                ranges::reverse(temp);

                int k = stoi(num);

                while(k--){
                    for(char &c : temp) st.push(c);
                }
            }
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
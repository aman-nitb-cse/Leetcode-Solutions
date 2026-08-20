// Last updated: 8/20/2026, 9:10:54 PM

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> st;
        int curr = 0;
        char op = '+';
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (isdigit(c)) {
                curr = (curr * 10) + (c - '0');
            }

            if (!isdigit(c) && c != ' ' || i == len - 1) {

                if (op == '-')  st.push(-curr);
                else if (op == '+') st.push(curr);
                else if (op == '*') st.top() *= curr;
                else if (op == '/') st.top() /= curr;


                op = c;
                curr = 0;
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

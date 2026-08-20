// Last updated: 8/20/2026, 9:06:37 PM
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";

        stack<char> st;
        for(char& c : num){
            while(!st.empty() && c < st.top() && k){
                st.pop();
                k--;
            }
            st.push(c);
        }

        // remove remaining k from end
        while(k && !st.empty()){
            st.pop();
            k--;
        }

        num = "";
        while(!st.empty()){
            num += st.top();
            st.pop();
        }
        ranges::reverse(num);

        // remove leading zeros
        int i = 0;
        while(i < num.size() && num[i] == '0') i++;
        num = num.substr(i);

        return num.empty() ? "0" : num;
    }
};
// Last updated: 6/24/2026, 3:29:42 AM
class Solution {
public:
    bool isconsecutive(char a, char b){
        return (a == b + 1) or (b == a + 1) or (a == 'a' and b == 'z') or ((a == 'z' and b == 'a'));
    }

    string resultingString(string s) {
        stack <char> st;
        for(char &c : s){
            if(st.empty() or !isconsecutive(st.top(), c)) st.push(c);
            else st.pop();
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
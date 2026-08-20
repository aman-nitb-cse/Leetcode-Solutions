// Last updated: 8/20/2026, 9:08:08 PM
class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        stack<char> st;
        for(char &i : s){
            if(isVowel(i)) st.push(i);
        }

        for(char &i : s){
            if(isVowel(i)){
                i = st.top();
                st.pop();
            }
        }
        return s;
    }
};
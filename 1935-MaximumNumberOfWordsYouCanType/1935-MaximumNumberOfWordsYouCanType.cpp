// Last updated: 11/6/2026, 5:06:57 AM
class Solution {
public:
    int canBeTypedWords(string s, string b) {
        unordered_set<char> st(b.begin(), b.end());
        bool isbroken = false;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(!isbroken) count++;
                isbroken = false;
                continue;
            }

            if(st.find(s[i]) != st.end()) isbroken = true;
        }
        return count + !isbroken;
    }
};
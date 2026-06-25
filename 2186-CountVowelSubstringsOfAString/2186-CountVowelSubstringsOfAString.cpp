// Last updated: 6/25/2026, 11:13:20 PM
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int countVowelSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i])) continue;
            unordered_set <char> st;
            for(int j = i; isVowel(s[j]) and j < s.size(); j++){
                st.insert(s[j]);
                count += st.size() >= 5;
            }
        }
        return count;
    }
};
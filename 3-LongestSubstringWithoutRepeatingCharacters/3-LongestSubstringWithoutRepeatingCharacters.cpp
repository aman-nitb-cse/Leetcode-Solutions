// Last updated: 8/20/2026, 9:20:43 PM
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l = 0;
        int s = 0, e = 0;
        unordered_set <char> st;
        st.insert(str[0]);
        while(e < str.size() and s <= e){
            l = max(l, e - s + 1);
            e++;
            if(st.find(str[e]) == st.end()) st.insert(str[e]);
            else {
                while(str[s] != str[e]) st.erase(str[s++]);
                s++;
            }
        }
        return l;
    }
};
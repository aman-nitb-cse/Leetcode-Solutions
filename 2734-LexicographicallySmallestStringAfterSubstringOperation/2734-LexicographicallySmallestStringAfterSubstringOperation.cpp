// Last updated: 11/6/2026, 4:50:50 AM
class Solution {
public:
    string smallestString(string s) {
        int n = s.size();

        int i = 0;
        while(i < n && s[i] == 'a') i++;

        if(i == n) s.back() = 'z';

        while(i < n && s[i] != 'a') s[i++]--;

        return s;
    }
};
// Last updated: 6/24/2026, 3:32:22 AM
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
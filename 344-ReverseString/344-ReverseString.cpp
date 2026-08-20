// Last updated: 8/20/2026, 9:08:13 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) swap(s[l++], s[r--]);
    }
};
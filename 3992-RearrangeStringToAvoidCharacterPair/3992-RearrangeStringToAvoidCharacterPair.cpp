// Last updated: 11/6/2026, 4:31:43 AM
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        ranges::sort(s);

        if(y > x) ranges::reverse(s);

        return s;
    }
};
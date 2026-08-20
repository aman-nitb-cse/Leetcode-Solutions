// Last updated: 8/20/2026, 8:27:03 PM
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        ranges::sort(s);

        if(y > x) ranges::reverse(s);

        return s;
    }
};
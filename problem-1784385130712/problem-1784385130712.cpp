// Last updated: 7/18/2026, 8:02:10 PM
1class Solution {
2public:
3    string rearrangeString(string s, char x, char y) {
4        ranges::sort(s);
5
6        if(y > x) ranges::reverse(s);
7
8        return s;
9    }
10};
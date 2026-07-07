// Last updated: 7/8/2026, 1:06:40 AM
1class Solution {
2public:
3    bool isPalindrome(int x) {
4        string s = to_string(x);
5
6
7        for(int i = 0; i < s.size() / 2; i++){
8            if(s[i] != s[s.size() - 1 - i]) return false;
9        }
10
11        return true;
12    }
13};
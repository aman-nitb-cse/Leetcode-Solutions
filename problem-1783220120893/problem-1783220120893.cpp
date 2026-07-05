// Last updated: 7/5/2026, 8:25:20 AM
1class Solution {
2public:
3    bool canMakeSubsequence(string s, string t) {
4        int i = 0, j = 0, n = s.size();
5        
6        for(char &c : t){
7            int _i = i;
8            int _j = j;
9
10            if(_j < n && s[_j] == c) j = _j + 1;
11            else j = _j;
12
13            if(_i < n) j = max(j, _i + 1);
14
15            if(_i < n && s[_i] == c) i = _i + 1;
16            else i = _i;
17        }
18
19        return max(i, j) == n;
20    }
21};
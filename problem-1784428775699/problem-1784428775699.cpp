// Last updated: 7/19/2026, 8:09:35 AM
1class Solution {
2public:
3    bool canReach(vector<int>& s, vector<int>& t) {
4        return ((s[0] + s[1]) & 1) == ((t[0] + t[1]) & 1);
5    }
6};
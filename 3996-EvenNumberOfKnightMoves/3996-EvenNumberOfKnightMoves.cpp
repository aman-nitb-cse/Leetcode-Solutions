// Last updated: 11/6/2026, 4:31:20 AM
class Solution {
public:
    bool canReach(vector<int>& s, vector<int>& t) {
        return ((s[0] + s[1]) & 1) == ((t[0] + t[1]) & 1);
    }
};
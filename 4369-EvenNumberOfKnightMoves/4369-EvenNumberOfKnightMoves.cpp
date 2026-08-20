// Last updated: 8/20/2026, 8:26:52 PM
class Solution {
public:
    bool canReach(vector<int>& s, vector<int>& t) {
        return ((s[0] + s[1]) & 1) == ((t[0] + t[1]) & 1);
    }
};
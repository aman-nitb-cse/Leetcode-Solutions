// Last updated: 11/6/2026, 4:37:42 AM
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        ranges::reverse(s);
        return abs(stoi(s) - n);
    }
};
// Last updated: 6/24/2026, 3:28:27 AM
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        ranges::reverse(s);
        return abs(stoi(s) - n);
    }
};
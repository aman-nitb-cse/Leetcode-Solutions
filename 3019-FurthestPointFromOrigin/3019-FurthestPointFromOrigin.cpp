// Last updated: 6/24/2026, 3:31:56 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l = ranges::count(s, 'L');
        int r = ranges::count(s, 'R');
        int _ = ranges::count(s, '_');

        return _ + abs(l - r);
    }
};
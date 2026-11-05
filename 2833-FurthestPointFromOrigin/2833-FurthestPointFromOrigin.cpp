// Last updated: 11/6/2026, 4:49:34 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int l = ranges::count(s, 'L');
        int r = ranges::count(s, 'R');
        int _ = ranges::count(s, '_');

        return _ + abs(l - r);
    }
};
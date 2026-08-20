// Last updated: 8/20/2026, 9:01:25 PM
class Solution {
public:
    bool judgeCircle(string s) {
        return !(ranges::count(s, 'L') - ranges::count(s, 'R') || ranges::count(s, 'U') - ranges::count(s, 'D'));
    }
};
// Last updated: 6/24/2026, 3:27:00 AM
class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);

        return s[0] != x + '0' && ranges::count(s, x + '0') != 0;
    }
};
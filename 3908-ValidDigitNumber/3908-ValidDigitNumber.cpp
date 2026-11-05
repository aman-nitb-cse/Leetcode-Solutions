// Last updated: 11/6/2026, 4:33:52 AM
class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);

        return s[0] != x + '0' && ranges::count(s, x + '0') != 0;
    }
};
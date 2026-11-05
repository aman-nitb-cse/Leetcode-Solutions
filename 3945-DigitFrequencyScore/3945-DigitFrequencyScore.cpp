// Last updated: 11/6/2026, 4:32:32 AM
class Solution {
public:
    int digitFrequencyScore(int n) {
        string s = to_string(n);

        int sc = 0;

        for(char c = '0'; c <= '9'; c++){
            sc += (c - '0') * ranges::count(s, c);
        }

        return sc;
    }
};
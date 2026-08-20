// Last updated: 8/20/2026, 8:37:16 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        sort(s.begin(), s.begin() + n / 2);
        sort(s.rbegin(), s.rbegin() + n / 2);

        return s;
    }
};
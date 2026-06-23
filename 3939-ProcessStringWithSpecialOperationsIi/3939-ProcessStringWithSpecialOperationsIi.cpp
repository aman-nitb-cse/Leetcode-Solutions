// Last updated: 6/24/2026, 3:29:30 AM
class Solution {
    typedef long long ll;
public:
    char processStr(string s, ll k) {
        int n = s.size();
        ll len = 0;

        for (auto& ch : s) {
            if (ch == '*')
                len = max(len - 1, 0LL);
            else if (ch == '#')
                len *= 2;
            else if (ch != '%')
                len++;
        }

        if (k >= len) return '.';

        for (int i = n - 1;; i--) {
            switch (s[i]) {
            case '*':
                len++;
                break;
            case '#':
                len /= 2;
                k %= len;
                break;
            case '%':
                k = len - 1 - k;
                break;
            default:
                if (len == k + 1)
                    return s[i];
                len--;
            }
        }
    }
};
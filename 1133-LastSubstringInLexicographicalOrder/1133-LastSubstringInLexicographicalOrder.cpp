// Last updated: 8/20/2026, 8:55:41 PM
#define ull unsigned long long

class Solution {
public:
    string lastSubstring(string s) {

        int n = s.size();
        vector<ull> pref(n + 1, 0);
        vector<ull> pw(n + 1, 1);
        ull hash = 0;
        ull power = 131;

        for (int i = 0; i < n; i++) {

            pref[i + 1] = (pref[i] * power + (s[i] - 'a' + 1));
        }

        for (int i = 1; i <= n; i++) {
            pw[i] = (pw[i - 1] * power);
        }

        auto calcu = [&](int l, int r) {
            return (pref[r + 1] - pref[l] * pw[r - l + 1]);
        };

        int index = n - 1;
        char c = ranges::max(s);
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == c) {
                index = i;
                break;
            }
        }

        for (int i = index - 1; i >= 0; i--) {

            if (s[i] != c)  continue;

            int size = n - index;
            int low = i;
            int high = i + size - 1;
            while (low <= high) {

                int mid = low + (high - low) / 2;
                int size = mid - i + 1;
                if (calcu(i, mid) == calcu(index, index + size - 1)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (low == i + size) {
                index = i;
            } else {

                int size = low - i;
                if (s[low] > s[index + size]) {
                    index = i;
                }
            }
        }

        string ans;
        for (int i = index; i < n; i++) {
            ans += s[i];
        }
        return ans;
    }
};
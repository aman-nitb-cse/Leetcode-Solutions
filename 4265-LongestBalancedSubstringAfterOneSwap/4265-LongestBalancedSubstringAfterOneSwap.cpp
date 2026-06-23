// Last updated: 6/24/2026, 3:27:24 AM
class Solution {
public:
    int longestBalanced(string s) {
        // Map from prefix sum -> list of indices where that sum occurred
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(-1);

        // Count total 0s and 1s in the string
        int n = s.size();
        int total0s = ranges::count(s, '0');
        int total1s = n - total0s;

        int pref = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // +1 for '1', -1 for '0'
            pref += (s[i] == '1') ? 1 : -1;

            // Case 1: Exact balance — same prefix sum seen before
            if (mp.count(pref)) ans = max(ans, i - mp[pref][0]);

            // Case 2: two extra ones
            if (mp.count(pref - 2)) {
                for (int idx : mp[pref - 2]) {
                    int used0s    = (i - idx - 2) / 2; // (length - extra one) / 2
                    if (total0s > used0s) {
                        ans = max(ans, i - idx);
                        break;
                    }
                }
            }

            // Case 3: two extra zeros
            if (mp.count(pref + 2)) {
                for (int idx : mp[pref + 2]) {
                    int used1s = (i - idx - 2) / 2; // (length - extra zero) / 2
                    if (total1s > used1s) {
                        ans = max(ans, i - idx);
                        break;
                    }
                }
            }
            mp[pref].push_back(i);
        }

        return ans;
    }
};
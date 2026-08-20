// Last updated: 8/20/2026, 8:40:23 PM
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            array<int, 26> count{};
            for (int right = left; right < n; ++right) {
                const int index = s[right] - 'a';
                ++count[index];
                if (count[index] > 2) {
                    break;
                }
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};
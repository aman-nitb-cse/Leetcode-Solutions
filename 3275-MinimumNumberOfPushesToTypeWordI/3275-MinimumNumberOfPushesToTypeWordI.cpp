// Last updated: 6/24/2026, 3:31:26 AM
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int r = n / 8;
        return (4 * r + n % 8) * (r + 1);
    }
};
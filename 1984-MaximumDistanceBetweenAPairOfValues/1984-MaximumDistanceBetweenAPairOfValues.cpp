// Last updated: 6/25/2026, 11:14:25 PM
class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int ans = 0;

        for (int i = 0; i < a.size(); i++) {
            int it = upper_bound(b.begin() + i, b.end(), a[i], greater<int>()) - b.begin() - i - 1;
            ans = max(ans, it);
        }
        return ans;
    }
};
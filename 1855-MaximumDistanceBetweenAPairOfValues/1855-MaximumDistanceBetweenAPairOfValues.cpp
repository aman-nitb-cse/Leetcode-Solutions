// Last updated: 11/6/2026, 4:57:59 AM
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
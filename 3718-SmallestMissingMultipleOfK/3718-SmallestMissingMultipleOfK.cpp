// Last updated: 11/6/2026, 4:39:20 AM
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int ans = k;
        while (seen.count(ans)) {
            ans += k;
        }
        return ans;
    }
};
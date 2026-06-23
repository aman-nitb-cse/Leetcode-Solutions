// Last updated: 6/24/2026, 3:29:13 AM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return 1LL * k * (ranges::max(nums) - ranges::min(nums));
    }
};
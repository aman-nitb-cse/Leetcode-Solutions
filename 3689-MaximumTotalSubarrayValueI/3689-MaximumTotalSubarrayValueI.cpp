// Last updated: 11/6/2026, 4:40:21 AM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return 1LL * k * (ranges::max(nums) - ranges::min(nums));
    }
};
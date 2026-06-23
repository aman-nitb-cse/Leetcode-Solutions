// Last updated: 6/24/2026, 3:26:53 AM
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        auto peak = ranges::max_element(nums);
        long long diff = accumulate(nums.begin(), peak + 1, 0LL) - accumulate(peak, nums.end(), 0LL);
        return diff > 0 ? 0 : diff < 0 ? 1 : -1;
    }
};
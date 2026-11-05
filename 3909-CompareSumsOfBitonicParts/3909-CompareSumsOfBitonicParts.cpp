// Last updated: 11/6/2026, 4:33:35 AM
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        auto peak = ranges::max_element(nums);
        long long diff = accumulate(nums.begin(), peak + 1, 0LL) - accumulate(peak, nums.end(), 0LL);
        return diff > 0 ? 0 : diff < 0 ? 1 : -1;
    }
};
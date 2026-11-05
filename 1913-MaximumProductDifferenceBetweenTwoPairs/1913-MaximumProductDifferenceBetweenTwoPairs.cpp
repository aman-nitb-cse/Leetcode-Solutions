// Last updated: 11/6/2026, 4:57:12 AM
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();

        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
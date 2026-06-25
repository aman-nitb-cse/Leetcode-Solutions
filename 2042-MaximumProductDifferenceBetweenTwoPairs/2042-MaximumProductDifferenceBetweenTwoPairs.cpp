// Last updated: 6/25/2026, 11:14:07 PM
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();

        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
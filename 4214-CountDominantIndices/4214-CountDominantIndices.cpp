// Last updated: 6/24/2026, 3:28:04 AM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            nums[i - 1] += nums[i];
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] - nums[i + 1] > nums[i + 1] / (n - 1 - i)) count++;
        }
        return count;
    }
};
// Last updated: 8/20/2026, 9:04:17 PM
class Solution {
public:
    int findPoisonedDuration(vector<int>& nums, int x) {
        int ans = x;
        for(int i = 1; i < nums.size(); i++){
            int start = max(nums[i], nums[i - 1] + x);
            int end = nums[i] + x - 1;

            ans += end - start + 1;
        }
        return ans;
    }
};
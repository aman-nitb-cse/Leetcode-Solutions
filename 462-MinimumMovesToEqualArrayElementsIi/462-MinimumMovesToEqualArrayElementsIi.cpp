// Last updated: 8/20/2026, 9:04:58 PM
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ranges::sort(nums);
        int med = nums[nums.size()/2];

        int ans = 0;
        for(int x : nums)
            ans += abs(x - med);

        return ans;
    }
};
// Last updated: 8/20/2026, 9:04:46 PM
class Solution {
public:
    int target;
    bool solve(vector<int>& nums, int curr = 0, int x = 4, int i = 0){
        if(x == 0) return true;
        if(curr == target) return solve(nums, 0, x - 1);
        if(i == nums.size() || curr > target) return false;
        if(nums[i] == 0) return solve(nums, curr, x, i + 1);

        // take
        int old = nums[i];
        nums[i] = 0;
        bool ans = solve(nums, curr + old, x, i + 1);
        nums[i] = old;
        if(ans) return true;

        // skip
        i++;
        while(i < nums.size() && nums[i] == nums[i - 1]) i++;
        return solve(nums, curr, x, i);
    }
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        ranges::sort(nums, greater<int>());
        if(sum % 4) return false;
        target = sum / 4;
        return solve(nums);
    }
};
// Last updated: 11/6/2026, 4:57:51 AM
class Solution {
public:
    int ans = 0;

    void backtrack(vector<int>& nums, int i = 0, int prev = 0){
        if(i == nums.size()) return;

        // skip
        backtrack(nums, i + 1, prev);
        // take
        prev ^= nums[i];
        ans += prev;
        backtrack(nums, i + 1, prev);
    }

    int subsetXORSum(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }
};
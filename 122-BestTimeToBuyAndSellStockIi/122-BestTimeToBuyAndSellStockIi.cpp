// Last updated: 8/20/2026, 9:14:19 PM
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        for(int i = nums.size() - 1; i; i--){
            if(nums[i] > nums[i - 1]) nums[i] -= nums[i - 1];
            else nums[i] = 0;
        }
        return accumulate(nums.begin() + 1, nums.end(), 0);
    }
};
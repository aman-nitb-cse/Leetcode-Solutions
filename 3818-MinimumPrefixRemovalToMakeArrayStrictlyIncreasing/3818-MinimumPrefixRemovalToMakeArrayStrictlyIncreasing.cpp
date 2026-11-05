// Last updated: 11/6/2026, 4:37:00 AM
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i;
        for(i = nums.size() - 1; i > 0; i--){
            if(nums[i] <= nums[i - 1]) break;
        }
        return i;
    }
};
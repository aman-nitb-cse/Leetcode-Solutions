// Last updated: 6/25/2026, 11:21:40 PM
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int l1 = 0;
        int l2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[l1]) l1 = i;
        }

        if(l1 == 0) l2 = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[l2] && nums[i] != nums[l1]) l2 = i;
        }

        return (nums[l1] >= nums[l2] * 2) ? l1 : -1;
    }
};
// Last updated: 8/20/2026, 9:16:31 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int idx = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] == nums[i]) count++;
            else count = 0;

            if(count < 2) nums[idx++] = nums[i];
        }
        return idx;
    }
};
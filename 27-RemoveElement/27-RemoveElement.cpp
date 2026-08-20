// Last updated: 8/20/2026, 9:19:08 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};
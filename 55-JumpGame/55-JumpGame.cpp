// Last updated: 8/20/2026, 9:17:41 PM
class Solution {
public:
    bool canJump(vector<int>& nums, int i = 0) {
        int n = nums.size();
        if(i + nums[i] >= n - 1) return true;
        if(nums[i] == 0) return false;
        int maxReach = 0;
        int index = i + 1;
        for(int j = i + 1; j <= i + nums[i]; j++){
            if(j + nums[j] > maxReach){
                maxReach = j + nums[j];
                index = j;
            }
        }
        return canJump(nums, index);
    }
};
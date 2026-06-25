// Last updated: 6/25/2026, 11:11:22 PM
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for(int i = n - 1; i; i--){
            for(int j = 0; j < i; j++){
                if(!nums[j] and nums[j + 1]) swap(nums[j], nums[j + 1]);
            }
        }
        return nums;
    }
};
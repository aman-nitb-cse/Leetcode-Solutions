// Last updated: 6/24/2026, 3:30:22 AM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i != nums[i] && nums[nums[i]] != nums[i]) {
                swap(nums[i], nums[nums[i]]);
                i--;
            }
        }
        return {nums[n - 2], nums[n - 1]};
    }
};
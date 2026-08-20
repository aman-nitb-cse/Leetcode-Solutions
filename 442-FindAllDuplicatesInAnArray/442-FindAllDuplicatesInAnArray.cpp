// Last updated: 8/20/2026, 9:05:49 PM
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 != nums[i] && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) ans.push_back(nums[i]);
        }
        return ans;
    }
};
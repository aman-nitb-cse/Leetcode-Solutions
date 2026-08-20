// Last updated: 8/20/2026, 9:05:36 PM
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i + 1){
                int idx = nums[i] - 1;
                if(nums[idx] == idx + 1) i++;
                else swap(nums[idx], nums[i]);
            }
            else i++;
        }
        int j = 0;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) nums[j++] = i + 1;
        }
        nums.resize(j);
        return nums;
    }
};
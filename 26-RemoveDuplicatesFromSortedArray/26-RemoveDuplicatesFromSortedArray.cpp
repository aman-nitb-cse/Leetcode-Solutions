// Last updated: 8/20/2026, 9:19:12 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = 0; // current index if solved arr
        for(int i = 0; i < n; i++){
            if(nums[curr] != nums[i]){ 
                nums[++curr] = nums[i];
            }
        }
        return curr + 1;
    }
};
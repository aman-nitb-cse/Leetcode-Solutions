// Last updated: 11/6/2026, 4:33:24 AM
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int p = nums[i] & 1;
            nums[i] = 0;
            for(int j = i + 1; j < n; j++){
                nums[i] += p ^ (nums[j] & 1);
            }
        }
        return nums;
    }
};
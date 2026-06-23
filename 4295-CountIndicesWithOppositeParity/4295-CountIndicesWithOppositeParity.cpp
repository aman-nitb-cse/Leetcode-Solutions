// Last updated: 6/24/2026, 3:26:49 AM
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
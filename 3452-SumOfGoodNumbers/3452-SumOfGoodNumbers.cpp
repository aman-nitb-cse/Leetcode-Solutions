// Last updated: 11/6/2026, 4:43:51 AM
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(i - k >= 0 && nums[i] <= nums[i - k]) continue;
            if(i + k < n && nums[i] <= nums[i + k]) continue; 
            sum += nums[i];
        }
        return sum;
    }
};
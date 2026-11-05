// Last updated: 11/6/2026, 4:34:34 AM
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= nums[i - 1]) continue;
            ans += nums[i - 1] - nums[i];
        }
        return ans;
    }
};
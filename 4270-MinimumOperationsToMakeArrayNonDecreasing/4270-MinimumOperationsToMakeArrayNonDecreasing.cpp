// Last updated: 6/24/2026, 3:27:18 AM
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
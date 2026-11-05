// Last updated: 11/6/2026, 4:30:55 AM
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int ans = 0;

        for(int i = 1; i + 1 < nums.size(); i++){
            if(nums[i] < min(nums[i + 1], nums[i - 1])) ans -= nums[i];
            else if(nums[i] > max(nums[i + 1], nums[i - 1])) ans += nums[i];
        }

        return ans;
    }
};
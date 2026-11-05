// Last updated: 11/6/2026, 4:35:15 AM
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int prev1 = -1;
        int prev2 = -1;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) prev1 = i;
            else if(nums[i] == 2) prev2 = i;

            if(prev1 != -1 && prev2 != -1) ans = min(ans, abs(prev1 - prev2));
        }
        return ans < INT_MAX ? ans : -1;
    }
};
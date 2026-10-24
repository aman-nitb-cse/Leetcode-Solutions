// Last updated: 10/24/2026, 8:02:17 PM
1class Solution {
2public:
3    int peakValleyDifference(vector<int>& nums) {
4        int ans = 0;
5
6        for(int i = 1; i + 1 < nums.size(); i++){
7            if(nums[i] < min(nums[i + 1], nums[i - 1])) ans -= nums[i];
8            else if(nums[i] > max(nums[i + 1], nums[i - 1])) ans += nums[i];
9        }
10
11        return ans;
12    }
13};
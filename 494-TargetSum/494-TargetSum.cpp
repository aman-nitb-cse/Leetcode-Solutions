// Last updated: 8/20/2026, 9:04:21 PM
class Solution {
public:
    vector<unordered_map<int, int>> dp;
    int findTargetSumWays(vector<int>& nums, int target, int start = 0) {

        // initialization of dp
        if(!start) dp.resize(nums.size());

        // Base case 
        if(start == nums.size()) return target == 0;

        // check if it is already present in dp or not 
        if(dp[start].find(target) == dp[start].end()) dp[start][target] = findTargetSumWays(nums, target + nums[start], start + 1) + findTargetSumWays(nums, target - nums[start], start + 1);
        return dp[start][target];
    }
};
// Last updated: 8/20/2026, 9:06:21 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;

        int target = sum / 2;

        bitset <20001> dp;

        dp[0] = 1;

        for(int &i : nums){
            dp |= (dp << i);
        }
        return dp[target];
    }
};
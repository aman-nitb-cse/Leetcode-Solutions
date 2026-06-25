// Last updated: 6/25/2026, 11:18:29 PM
class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / 2;

        bitset<3001> dp;
        dp.set(0);

        for(int &i : nums) dp |= (dp << i);

        for(int i = target; i <= sum; i++){
            if(dp[i]) return abs(2 * i - sum);
        }
        return sum;
    }
};
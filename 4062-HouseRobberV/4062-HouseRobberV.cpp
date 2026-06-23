// Last updated: 6/24/2026, 3:28:59 AM
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& c) {
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            // take prev if colour is diffrent
            if(c[i] != c[i - 1]) dp[i] += nums[i] + dp[i - 1];
            // same coulour
            else {
                // dp[i] = dp[i - 1];
                // if(i > 1) dp[i] = max(dp[i], nums[i] + dp[i - 2]);

                dp[i] = nums[i];
                if(i > 1) dp[i] += dp[i - 2];
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }
        return dp.back();
    }
};
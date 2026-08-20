// Last updated: 8/20/2026, 9:12:19 PM
class Solution {
public:
    // space optimization to o(k)
    int maxProfit(int _k, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(_k + 1, vector<int> (2));

        for(int i = n - 1; i >= 0; i--){
            for(int j = _k; j >= 0; j--){
                for(int k = 0; k <= 1; k++){
                    if(k){ // can buy
                        dp[j][k] = max(
                            -nums[i] + dp[j][0], // buy
                            dp[j][1] // skip
                        );
                    }
                    else if(j == 0) dp[0][k] = dp[0][0];
                    else  // can sell
                        dp[j][k] = max(
                            nums[i] + dp[j-1][1], // sell
                            dp[j][0] // skip
                        );
                }
            }
        }
        return dp[_k][1];
    }
};
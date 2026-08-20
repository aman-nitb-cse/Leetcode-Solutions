// Last updated: 8/20/2026, 9:14:16 PM
class Solution {
public:
    int maxProfit(vector<int>& nums){
        int n = nums.size();
        int dp[3][2];
        memset(dp, 0, sizeof(dp));

        for(int i = n - 1; i >= 0; i--){
            for(int j = 2; j >= 0; j--){
                for(int k = 0; k <= 1; k++){
                    if(k){ // can buy
                        dp[j][k] = max(
                            -nums[i] + dp[j][0],
                            dp[j][1]
                        );
                    }
                    else if(j > 0) 
                            dp[j][k] = max(
                                nums[i] + dp[j-1][1],
                                dp[j][0]
                            );
                    else dp[j][k] = dp[j][0];
                }
            }
        }

        return dp[2][1];
    }
};
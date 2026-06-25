// Last updated: 6/25/2026, 11:20:51 PM
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1));

        dp[0][0] = 0;

        for(int i = 0; i < n; i++){
            double sum = 0;

            for(int j = i; j < n; j++){
                sum += nums[j];

                for(int x = 0; x <= min(i, k - 1); x++) {
                    if(dp[i][x] != -1)  
                        dp[j + 1][x + 1] = max(dp[j + 1][x + 1], dp[i][x] + sum / (j - i + 1));
                }
            }
        }

        return dp[n][k];
    }
};
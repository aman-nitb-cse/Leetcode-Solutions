// Last updated: 6/24/2026, 3:30:38 AM
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        vector<vector<int>> dp(k, vector<int>(k));

        int ans = 0;

        for(int &x : nums){

            int cur = x % k;

            for(int p = 0; p < k; p++){

                dp[p][cur] = dp[cur][p] + 1;

                ans = max(ans, dp[p][cur]);
            }
        }

        return ans;
    }
};
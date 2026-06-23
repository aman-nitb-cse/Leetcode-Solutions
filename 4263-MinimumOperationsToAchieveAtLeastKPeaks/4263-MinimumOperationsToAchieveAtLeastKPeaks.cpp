// Last updated: 6/24/2026, 3:27:27 AM
class Solution {
public:
    int INF = 1e9;

    int solve(vector<int>& nums, int l, int r, int k){
        int n = nums.size();

        auto cost = [&](int i){
            return max(
                0,
                1 - nums[i] + max(
                    (i ? nums[i - 1] : nums[n - 1]),
                    (i + 1 == n ? nums[0] : nums[i + 1])
                )
            );
        };

        int len = r - l + 1;
        vector<vector<int>> dp(len, vector<int>(k + 1, INF));

        for(int i = 0; i < len; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i < len; i++){
            for(int j = 1; j <= k; j++){

                int idx = l + i;

                // take
                if(i >= 2) dp[i][j] = min(dp[i][j], cost(idx) + dp[i-2][j-1]);
                else if(j == 1) dp[i][j] = min(dp[i][j], cost(idx));

                // skip
                if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }
        return dp[len-1][k];
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n / 2) return -1;

        // case1: include 0 → exclude n-1
        int case1 = solve(nums, 0, n-2, k);

        // case2: exclude 0 → use 1 to n-1
        int case2 = solve(nums, 1, n-1, k);

        return min(case1, case2);
    }
};
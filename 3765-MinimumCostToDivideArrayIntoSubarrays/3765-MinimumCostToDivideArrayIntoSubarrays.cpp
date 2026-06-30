// Last updated: 6/30/2026, 2:24:14 PM
class Solution {
public:
    using ll = long long;

    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();

        // Prefix sum of nums
        for(int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        // Suffix sum of cost
        for(int i = n - 2; i >= 0; i--)
            cost[i] += cost[i + 1];

        vector<ll> dp(n + 1, LLONG_MAX);

        // dp[i] = minimum cost of first i elements
        dp[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                ll costSum = cost[i] - (j + 1 < n ? cost[j + 1] : 0);

                dp[j + 1] = min(
                    dp[j + 1],
                    dp[i] + nums[j] * costSum + k * cost[i]
                );
            }
        }

        return dp[n];
    }
};
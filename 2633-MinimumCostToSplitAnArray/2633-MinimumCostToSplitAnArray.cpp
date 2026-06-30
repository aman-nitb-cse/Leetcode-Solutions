// Last updated: 6/30/2026, 2:14:25 PM
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> cost(n, vector<int> (n));

        
        for(int i = 0; i < n; i++){
            unordered_map<int,int> freq;
            int unique = 0;
            for(int j = i; j < n; j++){

                int &f = ++freq[nums[j]];

                unique += (f == 1) - (f == 2);

                cost[i][j] = k + j - i + 1 - unique;
            }
        }

        vector<int> dp(n + 1, INT_MAX); 
        // dp[i] = cost of first i elements

        dp[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                dp[j + 1] = min(dp[j + 1], dp[i] + cost[i][j]);
            }
        }

        return dp.back();
    }
};
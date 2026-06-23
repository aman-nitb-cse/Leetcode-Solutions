// Last updated: 6/24/2026, 3:28:09 AM
class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long NEG_INF = -4e15;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();
        const int m = nums2.size();
        dp.assign(n + 1, vector<vector<long long>> (m + 1, vector<long long> (k + 1, NEG_INF)));
        dp[0][0][0] = 0;

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                for(int t = 0; t <= k; t++){
                    if (t > min(i, j)) continue;
                    long long skip_i = NEG_INF;
                    long long skip_j = NEG_INF;
                    long long take = NEG_INF;
                    if(i) skip_i = dp[i - 1][j][t];
                    if(j) skip_j = dp[i][j - 1][t];
                    if(i && j && t && dp[i - 1][j - 1][t - 1] != NEG_INF) take = dp[i - 1][j - 1][t - 1] + 1LL * nums1[i - 1] * nums2[j - 1];
                    dp[i][j][t] = max({skip_i, skip_j, take, dp[i][j][t]});
                }
            }
        }
        return dp[n][m][k];
    }
};
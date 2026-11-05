// Last updated: 11/6/2026, 5:11:22 AM
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<long long> dp(k + 1);
        int m;
        for(m = 0; dp[k] < n; m++){
            for(int i = k; i >= 1; i--) 
                dp[i] = dp[i] + dp[i - 1] + 1;
        }
        return m;
    }
};
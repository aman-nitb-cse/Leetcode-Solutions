// Last updated: 6/25/2026, 11:20:10 PM
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
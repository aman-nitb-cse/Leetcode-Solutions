// Last updated: 8/20/2026, 9:10:00 PM
class Solution {
public:
    vector<int> dp = {0, 1};
    void solve(){
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        for(int i = 2; i < dp.size(); i++){
            dp[i] = min({

                2 * dp[i2], 
                3 * dp[i3], 
                5 * dp[i5]

            });

            if(dp[i] == 2 * dp[i2]) i2++;
            if(dp[i] == 3 * dp[i3]) i3++;
            if(dp[i] == 5 * dp[i5]) i5++;
        }
    }

    int nthUglyNumber(int n) {
        dp.resize(n + 1);
        solve();
        return dp.back();
    }
};
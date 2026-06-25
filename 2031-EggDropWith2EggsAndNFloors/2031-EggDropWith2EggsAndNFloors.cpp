// Last updated: 6/25/2026, 11:14:09 PM
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int f, int egg){
        if(egg == 1 || f < 2) return f;
        if(dp[f][egg] != -1) return dp[f][egg];

        int ans = f;
        for(int i = 1; i <= f; i++){
            ans = min(ans, 1 + max(
                solve(i - 1, egg - 1),
                solve(f - i, egg)
            ));
        }
        return dp[f][egg] = ans;
    }

    int twoEggDrop(int f) {
        dp.assign(f + 1, vector<int>(3, -1));
        return solve(f, 2);
    }
};
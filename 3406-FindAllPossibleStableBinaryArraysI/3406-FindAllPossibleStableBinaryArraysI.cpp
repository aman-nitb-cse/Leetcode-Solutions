// Last updated: 6/24/2026, 3:30:52 AM
class Solution {
public:
    int k;
    int dp[201][201][201][2];
    const int mod = 1e9 + 7;
    int solve(int f0, int f1, int f = 0, int prev = 0){
        if(f0 < 0 || f1 < 0) return 0;
        if(f0 == 0 && f1 == 0) return 1;
        if(dp[f0][f1][f][prev] != -1) return dp[f0][f1][f][prev];
        if(f == k) {
            if(prev) return dp[f0][f1][f][prev] = solve(f0 - 1, f1, 1, 0) % mod;
            return dp[f0][f1][f][prev] = solve(f0, f1 - 1, 1, 1) % mod;
        }

        return dp[f0][f1][f][prev] = (solve(f0, f1 - 1, prev ? f + 1 : 1, 1) + solve(f0 - 1, f1, prev ? 1 : 1 + f, 0)) % mod;
    }
    int numberOfStableArrays(int f0, int f1, int _k) {
        memset(dp, -1, sizeof(dp));
        k = _k;
        return solve(f0, f1);
    }
};
// Last updated: 6/25/2026, 11:18:04 PM
class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<long long>> C;
    int mod = 1e9 + 7;

    int f(int n, int k, int target) {
        if(n == 0) return target == 0;
        if(n < 0 || k == 0) return 0;
        int& _dp = dp[n][k][target];
        if(_dp != -1) return _dp;
        _dp = 0;
        for(int i = 0; i <= n && i * k <= target; i++){
            _dp = (_dp + C[n][i] * f(n - i, k - 1, target - i * k)) % mod;
        }
        return _dp;
    }

    int numRollsToTarget(int n, int k, int target){
        C.assign(n + 1, vector<long long>(n + 1, 0));
        C[0][0] = 1;
        for(int i = 1; i <= n; i++){
            C[i][0] = 1;
            for(int j = 1; j <= i; j++)
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
        dp.assign(n + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, -1)));
        return f(n, k, target);
    }
};
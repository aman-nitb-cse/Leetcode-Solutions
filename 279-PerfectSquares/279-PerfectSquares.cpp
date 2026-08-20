// Last updated: 8/20/2026, 9:09:40 PM
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int target, int curr){
        if(target == 0) return 0;
        if(curr < 1 || target < 0) return 1e9;
        if(curr == 1) return target;
        if(dp[curr][target] != -1) return dp[curr][target];
        dp[curr][target] = min(solve(target, curr - 1), 1 + solve(target - curr * curr, curr));
        return dp[curr][target];
    }

    int numSquares(int n) {
        int root = sqrt(n);
        dp.assign(root + 1, vector<int> (n + 1, -1));
        return solve(n, root);
    }
};
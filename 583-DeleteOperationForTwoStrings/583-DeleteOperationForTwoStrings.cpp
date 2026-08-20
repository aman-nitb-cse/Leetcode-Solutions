// Last updated: 8/20/2026, 9:02:41 PM
class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &a, string &b, int i = 0, int j = 0){
        if(i == a.size() || j == b.size()) return a.size() + b.size() - i - j;

        if(dp[i][j] != -1) return dp[i][j];


        if(a[i] == b[j]) return dp[i][j] = solve(a, b, i + 1, j + 1);
        return dp[i][j] = 1 + min(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    }
    int minDistance(string a, string b) {
        dp.assign(a.size(), vector<int>(b.size(), -1));
        return solve(a, b);
    }
};
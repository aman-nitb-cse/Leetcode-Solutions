// Last updated: 6/24/2026, 3:29:15 AM
class Solution {
public:
    int m, n, k;
    vector<vector<vector<int>>> dp;

    int f(vector<vector<int>>& grid, int cost = 0, int i = 0, int j = 0) {
        if(i == m || j == n) return -1e9;

        cost += (grid[i][j] != 0);
        if(cost > k) return -1e9;

        if(i == m - 1 && j == n - 1) return grid[i][j];

        auto &_dp = dp[i][j][cost];
        if(_dp != -2) return _dp;

        int down = f(grid, cost, i + 1, j);
        int right = f(grid, cost, i, j + 1);

        int best = max(down, right);

        if(best < 0) return _dp = -1e9;

        return _dp = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int _k) {
        m = grid.size(), n = grid[0].size(), k = _k;
        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));

        int ans = f(grid);
        return ans < 0 ? -1 : ans;
    }
};
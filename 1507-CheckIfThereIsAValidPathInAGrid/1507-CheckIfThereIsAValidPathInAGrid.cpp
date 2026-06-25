// Last updated: 6/25/2026, 11:16:30 PM
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<int>>& grid, int i, int j, char entryFrom) {
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        if (visited[i][j]) return false;
        visited[i][j] = true;

        int x = grid[i][j];

        if (entryFrom == 'U') {
            if (x == 2) return (i==m-1 && j==n-1) || dfs(grid, i + 1, j, 'U');
            if (x == 5) return (i==m-1 && j==n-1) || dfs(grid, i, j - 1, 'R');
            if (x == 6) return (i==m-1 && j==n-1) || dfs(grid, i, j + 1, 'L');
        }
        else if (entryFrom == 'L') {
            if (x == 1) return (i==m-1 && j==n-1) || dfs(grid, i, j + 1, 'L');
            if (x == 3) return (i==m-1 && j==n-1) || dfs(grid, i + 1, j, 'U');
            if (x == 5) return (i==m-1 && j==n-1) || dfs(grid, i - 1, j, 'D');
        }
        else if (entryFrom == 'R') {
            if (x == 1) return (i==m-1 && j==n-1) || dfs(grid, i, j - 1, 'R');
            if (x == 4) return (i==m-1 && j==n-1) || dfs(grid, i + 1, j, 'U');
            if (x == 6) return (i==m-1 && j==n-1) || dfs(grid, i - 1, j, 'D');
        }
        else if (entryFrom == 'D') {
            if (x == 2) return (i==m-1 && j==n-1) || dfs(grid, i - 1, j, 'D');
            if (x == 3) return (i==m-1 && j==n-1) || dfs(grid, i, j - 1, 'R');
            if (x == 4) return (i==m-1 && j==n-1) || dfs(grid, i, j + 1, 'L');
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (char c : {'L', 'R', 'U', 'D'}) {
            visited.assign(m, vector<bool>(n, false));
            if (dfs(grid, 0, 0, c)) return true;
        }
        return false;
    }
};
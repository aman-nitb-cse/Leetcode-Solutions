// Last updated: 8/20/2026, 8:58:37 PM
class Solution {
public:
    bool isValid(vector<vector<int>>& g, int i, int j, int k) {
        bool seen[10] = {};

        for(int x = i; x < i + k; x++){
            for(int y = j; y < j + k; y++){
                int v = g[x][y];
                if(v < 1 || v > 9 || seen[v]) return false;
                seen[v] = true;
            }
        }

        int sum = 0;

        for (int x = i; x < i + k; x++) {
            int s = 0;
            for (int y = j; y < j + k; y++) s += g[x][y];
            if (x == i) sum = s;
            else if (sum != s) return false;
        }

        for (int y = j; y < j + k; y++) {
            int s = 0;
            for (int x = i; x < i + k; x++) s += g[x][y];
            if (sum != s) return false;
        }

        int s = 0;
        for (int d = 0; d < k; d++) s += g[i + d][j + d];
        if (sum != s) return false;

        s = 0;
        for (int d = 0; d < k; d++) s += g[i + d][j + k - 1 - d];
        if (sum != s) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;

        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                res += isValid(grid, i, j, 3);
            }
        }

        return res;
    }
};
// Last updated: 11/6/2026, 5:05:42 AM
class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int m, n;
    
    bool dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)  return false;
        
        if (g[i][j] == 1) return true;
        
        g[i][j] = 1;
        
        bool isClosed = true;
        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];
            isClosed &= dfs(g, ni, nj);
        }
        
        return isClosed;
    }
    
    int closedIsland(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0 && dfs(g, i, j)) ans++;
            }
        }

        return ans;
    }
};
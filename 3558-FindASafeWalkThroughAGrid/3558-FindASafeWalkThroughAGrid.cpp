// Last updated: 7/2/2026, 11:35:35 PM
class Solution {
public:
    int m, n;
    int dir[5] = {1, 0, -1, 0, 1};
    vector<vector<int>> vis;

    bool f(vector<vector<int>>& g, int h, int i, int j){
        h -= g[i][j];

        if(h <= 0) return false;

        if(i == m - 1 && j == n - 1) return true;

        for(int d = 0; d < 4; d++){
            int ni = i + dir[d];
            int nj = j + dir[d + 1];

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && vis[ni][nj] < h){
                vis[ni][nj] = h;
                if(f(g, h, ni, nj)) return true;
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& g, int h) {
        m = g.size();
        n = g[0].size();

        vis.assign(m, vector<int>(n, -1));
        vis[0][0] = h;

        return f(g, h, 0, 0);
    }
};
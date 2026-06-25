// Last updated: 6/25/2026, 11:15:48 PM
class Solution {
public:
    vector<vector<int>> vis;
    int dir[5] = {0, 1, 0, -1, 0};

    bool dfs(vector<vector<char>>& g, int i, int j, int pi, int pj){
        vis[i][j] = 1;

        for(int k = 0; k < 4; k++){
            int ni = i + dir[k];
            int nj = j + dir[k + 1];

            if(ni < 0 || nj < 0 || ni >= g.size() || nj >= g[0].size() || g[ni][nj] != g[i][j])
                continue;
                
            if(!vis[ni][nj]){
                if(dfs(g, ni, nj, i, j)) return true;
            }
            else if(ni != pi || nj != pj){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        vis.assign(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(dfs(g, i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};
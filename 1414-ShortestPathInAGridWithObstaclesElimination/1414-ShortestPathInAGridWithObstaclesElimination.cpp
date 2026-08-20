// Last updated: 8/20/2026, 8:53:41 PM
class Solution {
public:
    int m, n;
    int dir[5] = {1, 0, -1, 0, 1};

    int shortestPath(vector<vector<int>>& g, int k) {
        m = g.size();
        n = g[0].size();

        if(m == 1 && n == 1) return 0;

        queue<array<int, 3>> q; // {i, j, steps}
        vector<vector<int>> vis(m, vector<int>(n, -1)); // stores remaining k

        q.push({0, 0, 0});
        vis[0][0] = k;

        while(!q.empty()){
            auto [i, j, steps] = q.front(); q.pop();

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n){

                    int nk = vis[i][j] - g[ni][nj];

                    if(nk >= 0 && vis[ni][nj] < nk){
                        if(ni == m - 1 && nj == n - 1) return steps + 1;

                        vis[ni][nj] = nk;
                        q.push({ni, nj, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
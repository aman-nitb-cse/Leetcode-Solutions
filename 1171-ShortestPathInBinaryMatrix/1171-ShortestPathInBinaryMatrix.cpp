// Last updated: 8/20/2026, 8:55:32 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();

        if(g[0][0] == 1 || g[n - 1][n - 1] == 1) return -1;

        queue<array<int,3>> q;
        q.push({0, 0, 0}); // {i, j, steps}
        g[0][0] = 1;

        int dir[] = {1, 0, -1, 0, 1, 1, -1, -1, 1};

        while(!q.empty()){
            auto [i, j, steps] = q.front(); q.pop();

            if(i == n - 1 && j == n - 1) return steps + 1;

            for(int d = 0; d < 8; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < n && !g[ni][nj]){
                    g[ni][nj] = 1; // mark visited
                    q.push({ni, nj, steps + 1});
                }
            }
        }

        return -1;
    }
};
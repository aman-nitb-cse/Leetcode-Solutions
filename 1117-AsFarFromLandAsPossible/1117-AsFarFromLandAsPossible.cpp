// Last updated: 8/20/2026, 8:55:53 PM
class Solution {
public:
    int maxDistance(vector<vector<int>>& g) {
        int n = g.size();

        queue<array<int,4>> q; //{dx, dy, i, j}

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]){
                    q.push({0, 0, i, j});
                }
            }
        }

        if(q.empty() || q.size() == n * n) return -1;

        int dist = 0;

        int dir[] = {1, 0, -1, 0, 1};

        while(!q.empty()){
            auto [dx, dy, i, j] = q.front(); q.pop();

            dist = max(dist, abs(dx) + abs(dy));

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < n && !g[ni][nj]){
                    g[ni][nj] = 1;
                    q.push({dx + dir[d], dy + dir[d + 1], ni, nj});
                }
            }
        }

        return dist;
    }
};
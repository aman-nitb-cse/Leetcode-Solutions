// Last updated: 7/18/2026, 12:23:08 AM
class Solution {
public:
    static constexpr int dir[5] = {1, 0, -1, 0, 1};

    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            array<int,4>,
            vector<array<int,4>>,
            greater<array<int,4>>
        > pq; // {time, i, j, edge time}

        dist[0][0] = 0;
        pq.push({0, 0, 0, 1});

        while(!pq.empty()){

            auto [t, i, j, delta] = pq.top();
            pq.pop();

            if(t != dist[i][j]) continue;

            if(i == m - 1 && j == n - 1) return t;

            for(int d = 0; d < 4; d++){

                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                int nt = max(t, grid[ni][nj]) + delta;

                if(dist[ni][nj] > nt){
                    dist[ni][nj] = nt;
                    pq.push({nt, ni, nj, 3 - delta});
                }
            }
        }

        return -1;
    }
};
// Last updated: 7/18/2026, 12:24:53 AM
class Solution {
public:
    static constexpr int dir[5] = {1, 0, -1, 0, 1};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            array<int,3>,
            vector<array<int,3>>,
            greater<array<int,3>>
        > pq; // {time, i, j}

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while(!pq.empty()){

            auto [t, i, j] = pq.top();
            pq.pop();

            if(t != dist[i][j]) continue;

            if(i == m - 1 && j == n - 1) return t;

            for(int d = 0; d < 4; d++){

                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                int nt = max(t + 1, grid[ni][nj]);

                if((nt - (t + 1)) & 1)
                    nt++;

                if(dist[ni][nj] > nt){

                    dist[ni][nj] = nt;
                    pq.push({nt, ni, nj});
                }
            }
        }

        return -1;
    }
};
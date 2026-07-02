// Last updated: 7/2/2026, 11:39:06 PM
class Solution {
public:
    int m, n;
    int dir[5] = {1, 0, -1, 0, 1};
    int minimumObstacles(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();

        deque<array<int, 2>> q; // {i, j}
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX)); // stores curr sum

        q.push_front({0, 0});
        vis[0][0] = 0;

        // 0/1 - BFS

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();

            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n) {

                    int nSum = vis[i][j] + g[ni][nj];

                    if (vis[ni][nj] > nSum) {

                        vis[ni][nj] = nSum;

                        if (g[ni][nj] == 0) q.push_front({ni, nj});
                        else q.push_back({ni, nj});
                    }
                }
            }
        }

        return vis[m - 1][n - 1];
    }
};
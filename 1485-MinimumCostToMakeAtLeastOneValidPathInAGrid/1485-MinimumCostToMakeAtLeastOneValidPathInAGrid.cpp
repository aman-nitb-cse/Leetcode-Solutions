// Last updated: 8/20/2026, 8:52:45 PM
class Solution {
public:
    static constexpr int dx[4] = {0, 0, 1, -1};
    static constexpr int dy[4] = {1, -1, 0, 0};

    int minCost(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        
        // 0-1 BFS
        deque<array<int,2>> q; // {i, j}
        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));

        q.push_back({0, 0});
        cost[0][0] = 0;

        while(!q.empty()){
            auto [i, j] = q.front(); q.pop_front();

            if(i == m - 1 && j == n - 1) break;

            for(int d = 1; d <= 4; d++){

                int ni = i + dx[d - 1];
                int nj = j + dy[d - 1];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

                if(int nCost = cost[i][j] + (g[i][j] != d); cost[ni][nj] > nCost) {
                    cost[ni][nj] = nCost;

                    if(g[i][j] == d) q.push_front({ni, nj}); 
                    else q.push_back({ni, nj});
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};

// 1 : R
// 2 : L
// 3 : D
// 4 : U
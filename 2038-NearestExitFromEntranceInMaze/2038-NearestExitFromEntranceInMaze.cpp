// Last updated: 8/20/2026, 8:48:43 PM
class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& e) {
        int m = g.size();
        int n = g[0].size();

        queue<array<int,3>> q; // {i, j, steps} 

        q.push({e[0], e[1], 0});
        g[e[0]][e[1]] = '+';

        int dir[] = {1, 0, -1, 0, 1};

        while(!q.empty()){
            auto [i, j, steps] = q.front(); q.pop();

            if(steps && (i == m - 1 || j == n - 1 || !i || !j)) return steps;

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && g[ni][nj] == '.'){
                    g[ni][nj] = '+'; // mark visited

                    q.push({ni, nj, steps + 1});
                }
            }
        }
        return -1;
    }
};
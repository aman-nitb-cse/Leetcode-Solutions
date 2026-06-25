// Last updated: 6/25/2026, 11:19:02 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 2) q.push({i, j});
                else if(g[i][j] == 1) fresh++;
            }
        }

        int x = 0;
        q.push({x, x--});

        // early exit
        if(fresh == 0) return 0;

        while(!q.empty() && fresh){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r < 0) {
                if(!q.empty()) {
                    q.push({x, x--});
                    continue;
                }
                break;
            }

            if(r && g[r - 1][c] == 1) {
                g[r - 1][c] = 2;
                q.push({r - 1, c});
                fresh--;
            }
            if(c && g[r][c - 1] == 1) {
                g[r][c - 1] = 2;
                q.push({r, c - 1});
                fresh--;
            }
            if(r + 1 != g.size() && g[r + 1][c] == 1) {
                g[r + 1][c] = 2;
                q.push({r + 1, c});
                fresh--;
            }
            if(c + 1 != g[0].size() && g[r][c + 1] == 1) {
                g[r][c + 1] = 2;
                q.push({r, c + 1});
                fresh--;
            }
        }

        return fresh ? -1 : -x;
    }
};
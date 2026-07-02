// Last updated: 7/2/2026, 11:37:37 PM
class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    int n;

    bool check(vector<vector<int>>& g, int safe){

        queue<array<int,2>> q;
        vector<vector<bool>> visited(n, vector<bool>(n));

        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();

            if(i == n - 1 && j == n - 1) return true;

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < n &&
                   !visited[ni][nj] && g[ni][nj] >= safe){
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& g) {
        n = g.size();

        queue<array<int,2>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]){
                    q.push({i, j});
                    g[i][j] = 0;
                }
                else g[i][j] = -1;
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < n && g[ni][nj] == -1){
                    g[ni][nj] = g[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        int l = 0, r = min(g[0][0], g[n - 1][n - 1]), ans = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(g, mid)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return ans;
    }
};
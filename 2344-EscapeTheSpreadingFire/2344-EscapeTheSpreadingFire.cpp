// Last updated: 6/30/2026, 2:15:18 PM
class Solution {
public:
    int m, n;
    static constexpr int dir[] = {1, 0, -1, 0, 1};
    bool check(vector<vector<int>> &fire, int wait){
        if(fire[0][0] != -1 && fire[0][0] <= wait) return false;

        queue<array<int, 3>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        q.push({0, 0, wait});   // {i, j, current time}
        visited[0][0] = true;

        while(!q.empty()){
            auto [i, j, t] = q.front();
            q.pop();

            if(i == m - 1 && j == n - 1) return true;

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj] || fire[ni][nj] == -2) continue;

                int nt = t + 1;

                if(fire[ni][nj] == -1 || nt < fire[ni][nj] || (nt == fire[ni][nj] && ni == m - 1 && nj == n - 1)){
                    visited[ni][nj] = true;
                    q.push({ni, nj, nt});
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& g) {
        m = g.size(), n = g[0].size();

        queue<array<int,2>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 1){
                    q.push({i, j});
                    g[i][j] = 0;
                }
                else if(g[i][j] == 0) g[i][j] = -1;
                else g[i][j] = -2;
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && g[ni][nj] == -1){
                    g[ni][nj] = g[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        int s = 0, e = m * n, ans = -1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(check(g, mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return ans == m * n ? 1e9 : ans;
    }
};
// Last updated: 8/20/2026, 9:06:28 PM
class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;

        for(int i = 0; i < m; i++){
            pq.push({h[i][0], i, 0});
            pq.push({h[i][n-1], i, n-1});
            h[i][0] = h[i][n-1] = -1;
        }

        for(int j = 1; j < n-1; j++){
            pq.push({h[0][j], 0, j});
            pq.push({h[m-1][j], m-1, j});
            h[0][j] = h[m-1][j] = -1;
        }

        int ans = 0;
        auto solve = [&](int ht, int x, int y){
            if(x < 0 || y < 0 || x >= m || y >= n || h[x][y] < 0) return;

            ans += max(0, ht - h[x][y]);
            pq.push({max(ht, h[x][y]), x, y});
            h[x][y] = -1;
        };

        while(!pq.empty()){
            auto [ht, x, y] = pq.top(); pq.pop();

            solve(ht, x, y + 1);
            solve(ht, x, y - 1);
            solve(ht, x + 1, y);
            solve(ht, x - 1, y);
        }
        return ans;
    }
};
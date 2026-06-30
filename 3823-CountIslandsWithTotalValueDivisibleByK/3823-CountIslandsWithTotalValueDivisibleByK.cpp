// Last updated: 6/30/2026, 1:28:37 PM
class Solution {
public:
    static constexpr int dir[] = {1, 0, -1, 0, 1};
    int dfs(vector<vector<int>>& g, int i, int j, int k){
        int sum = g[i][j] % k;
        g[i][j] = 0;

        for(int d = 0; d < 4; d++){
            int ni = i + dir[d];
            int nj = j + dir[d + 1];

            if(ni >= 0 && nj >= 0 && ni < g.size() && nj < g[0].size() && g[ni][nj]){
                sum += dfs(g, ni, nj, k);
                sum %= k;
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& g, int k) {
        int cnt = 0;

        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j]) cnt += !dfs(g, i, j, k);
            }
        }
        return cnt;
    }
};
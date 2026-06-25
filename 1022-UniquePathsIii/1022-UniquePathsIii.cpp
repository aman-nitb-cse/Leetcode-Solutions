// Last updated: 6/25/2026, 11:19:19 PM
class Solution {
public:
    int m, n;
    int ans = 0;
    int empty_cells = 0;
    void solve(vector<vector<int>>& g, int i, int j){
        if(i < 0 || i == m || j < 0 || j == n || g[i][j] == -1) return;
        if(g[i][j] == 2) {
            if(!empty_cells) ans++;
            return;
        }
        empty_cells--;
        g[i][j] = -1;
        solve(g, i, j + 1);
        solve(g, i, j - 1);
        solve(g, i + 1, j);
        solve(g, i - 1, j);
        empty_cells++;
        g[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        int r, c;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 1){
                    r = i;
                    c = j;
                    g[i][j] = 0;
                }
                if(g[i][j] == 0) empty_cells++;
            }
        }
        solve(g, r, c);
        return ans;
    }
};
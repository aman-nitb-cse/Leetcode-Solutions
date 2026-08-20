// Last updated: 8/20/2026, 8:56:08 PM
class Solution {
public:
    int m, n;
    void f(vector<vector<int>>& g, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n || !g[i][j]) return;

        g[i][j] = 0;
        f(g, i + 1, j);
        f(g, i, j + 1);
        f(g, i - 1, j);
        f(g, i, j - 1);
    }
    int numEnclaves(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();


        for(int i = 0; i < m; i++){
            if(g[i][0]) f(g, i, 0);
            if(g[i][n - 1]) f(g, i, n - 1);
        }

        for(int i = 0; i < n; i++){
            if(g[0][i]) f(g, 0, i);
            if(g[m - 1][i]) f(g, m - 1, i);
        }

        int ans = 0;
        for(auto &i : g){
            for(int &j : i){
                ans += j;
            }
        }
        return ans;
    }
};
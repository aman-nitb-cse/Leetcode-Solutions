// Last updated: 6/25/2026, 11:18:41 PM
class Solution {
public:
    void solve(vector<vector<int>>& g, int r, int c, int req){
        if(r < 0 || c < 0 || r == g.size() || c == g[0].size() || g[r][c] != req) return;
        
        if(r == 0 || c == 0 || r == g.size() - 1 || c == g[0].size() - 1) g[r][c] = -1;
        else if(g[r - 1][c] > 0 && g[r - 1][c] != req) g[r][c] = -1;
        else if(g[r + 1][c] > 0 && g[r + 1][c] != req) g[r][c] = -1;
        else if(g[r][c - 1] > 0 && g[r][c - 1] != req) g[r][c] = -1;
        else if(g[r][c + 1] > 0 && g[r][c + 1] != req) g[r][c] = -1;
        else g[r][c] = -2;

        solve(g, r - 1, c, req);
        solve(g, r + 1, c, req);
        solve(g, r, c - 1, req);
        solve(g, r, c + 1, req);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int r, int c, int color) {
        int old = g[r][c];
        solve(g, r, c, g[r][c]);
        for(vector<int> &v : g){
            for(int &i : v){
                if(i == -1) i = color;
                if(i == -2) i = old;
            }
        }
        return g;
    }
};
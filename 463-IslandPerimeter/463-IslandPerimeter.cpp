// Last updated: 8/20/2026, 9:04:53 PM
class Solution {
public:
    int solve(vector<vector<int>>& g, int r, int c){
        if(r < 0 || c < 0 || r == g.size() || c == g[0].size() || g[r][c] <= 0) return 0;
        g[r][c] = -1;
        int ans = 0;

        if(r == 0 || g[r - 1][c] == 0) ans++;
        if(r == g.size() - 1 || g[r + 1][c] == 0) ans++;
        if(c == 0 || g[r][c - 1] == 0) ans++;
        if(c == g[0].size() - 1 || g[r][c + 1] == 0) ans++;

        return ans + solve(g, r + 1, c) + solve(g, r, c + 1) + solve(g, r, c - 1) + solve(g, r - 1, c);
    }
    int islandPerimeter(vector<vector<int>>& g) {
        int count = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j] == 1) return solve(g, i, j);
            }
        }
        return 0;
    }
};
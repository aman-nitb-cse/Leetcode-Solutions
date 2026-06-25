// Last updated: 6/25/2026, 11:17:41 PM
class Solution {
public:
    int dfs(vector<vector<int>>& g, int r, int c){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] == 0) return 0;

        int gold = g[r][c];
        g[r][c] = 0;

        int best = max({
            dfs(g, r, c - 1),
            dfs(g, r, c + 1),
            dfs(g, r + 1, c),
            dfs(g, r - 1, c)
        });

        g[r][c] = gold;

        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& g) {
        int ans = 0;

        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j]){
                    ans = max(ans, dfs(g, i, j));
                }
            }
        }
        return ans;
    }
};
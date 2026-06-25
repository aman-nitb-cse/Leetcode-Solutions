// Last updated: 6/25/2026, 11:10:30 PM
class Solution {
public:
    int solve(vector<vector<int>>& g, int i, int j){
        if(i < 0 || j < 0 || i == g.size() || j == g[0].size() || g[i][j] == 0) return 0;
        int ans = g[i][j];
        g[i][j] = 0;
        return ans + solve(g, i + 1, j) + solve(g, i - 1, j) + solve(g, i, j - 1) + solve(g, i, j + 1);
    }
    int findMaxFish(vector<vector<int>>& g) {
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j]) ans = max(ans, solve(g, i, j));
            }
        }
        return ans;
    }
};
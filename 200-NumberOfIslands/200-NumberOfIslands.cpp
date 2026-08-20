// Last updated: 8/20/2026, 9:11:59 PM
class Solution {
public:
    void mark(vector<vector<char>>& g, int r, int c){
        if(r < 0 || c < 0 || r == g.size() || c == g[0].size() || g[r][c] == '0') return;
        g[r][c] = '0';
        mark(g, r + 1, c);
        mark(g, r, c + 1);
        mark(g, r - 1, c);
        mark(g, r, c - 1);
    }
    int numIslands(vector<vector<char>>& g) {
        int count = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j] == '0') continue;
                count++;
                mark(g, i, j);
            }
        }
        return count;
    }
};
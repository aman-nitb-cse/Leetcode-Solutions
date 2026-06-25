// Last updated: 6/25/2026, 11:37:08 PM
class Solution {
public:
    int get_area(vector<vector<int>>& g, int r, int c){
        if(r < 0 || c < 0 || r == g.size() || c == g[0].size() || g[r][c] == 0) return 0;
        g[r][c] = 0;

        return 1 + get_area(g, r + 1, c) + get_area(g, r, c + 1) + get_area(g, r - 1, c) + get_area(g, r, c - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int area = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[0].size(); j++){
                if(g[i][j] == 1) area = max(area, get_area(g, i, j));
            }
        }
        return area;
    }
};
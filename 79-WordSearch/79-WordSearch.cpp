// Last updated: 8/20/2026, 9:16:33 PM
class Solution {
public:
    vector<vector<bool>> taken;
    bool solve(vector<vector<char>>& b, string w, int r = 0, int c = 0, int i = 0){
        if(r < 0 || c < 0 || r == b.size() || c == b[0].size() || i == w.size()) return i == w.size();
        if(taken[r][c] || b[r][c] != w[i]) return false;
        taken[r][c] = true;
        bool ans = solve(b, w, r + 1, c, i + 1) || solve(b, w, r, c - 1, i + 1) || solve(b, w, r - 1, c, i + 1) || solve(b, w, r, c + 1, i + 1);
        taken[r][c] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& b, string w, int r = 0, int c = 0, int i = 0) {
        taken.assign(b.size(), vector<bool>(b[0].size(), false));
        for(int i = 0; i < b.size(); i++){
            for(int j = 0; j < b[0].size(); j++){
                if(b[i][j] == w.front() && solve(b, w, i, j, 0)) return true; 
            }
        }
        return false;
    }
};
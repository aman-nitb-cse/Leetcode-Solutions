// Last updated: 8/20/2026, 9:13:54 PM
class Solution {
public:
    int m, n;
    void help(vector<vector<char>>& b, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n || b[i][j] != 'O') return;

        b[i][j] = '#';
        help(b, i + 1, j);
        help(b, i - 1, j);
        help(b, i, j + 1);
        help(b, i, j - 1);
    }
    void solve(vector<vector<char>>& b) {
        m = b.size(), n = b[0].size();
        for(int i = 0; i < m; i++){
            help(b, i, 0);
            help(b, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            help(b, 0, i);
            help(b, m - 1, i);
        }
        
        for(auto &v : b){
            for(char &c : v){
                if(c == 'O') c = 'X';
                else if(c == '#') c = 'O';
            }
        }
    }
};
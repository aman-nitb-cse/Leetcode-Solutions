// Last updated: 8/20/2026, 9:18:51 PM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector <vector<unordered_set <char>>> v(3, vector<unordered_set <char>>(3));
        for(int i = 0; i < 9; i++){
            unordered_set <char> r, c;
            for(int j = 0; j < 9; j++){
                if(v[i/3][j/3].find(b[i][j]) != v[i/3][j/3].end()) return false;
                if(r.find(b[i][j]) != r.end()) return false;
                if(c.find(b[j][i]) != c.end()) return false;
                if(b[i][j] != '.') r.insert(b[i][j]); 
                if(b[j][i] != '.') c.insert(b[j][i]);
                if(b[i][j] != '.') v[i/3][j/3].insert(b[i][j]);
            }
        }
        return true;
    }
};
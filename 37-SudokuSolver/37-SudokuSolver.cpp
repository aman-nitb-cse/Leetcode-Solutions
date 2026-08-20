// Last updated: 8/20/2026, 9:18:45 PM
class Solution {
public:
    vector<unordered_set<char>> row;
    vector<unordered_set<char>> col;
    vector<unordered_set<char>> box;

    void put(vector<vector<char>>& b, int i, int j, char c){
        b[i][j] = c;
        row[i].insert(c);
        col[j].insert(c);
        box[(i / 3) * 3 + (j / 3)].insert(c);
    }

    void remove(vector<vector<char>>& b, int i, int j, char c){
        b[i][j] = '.';
        row[i].erase(c);
        col[j].erase(c);
        box[(i / 3) * 3 + (j / 3)].erase(c);
    }

    bool check(int i, int j, char c){
        return !row[i].count(c) && !col[j].count(c) && !box[(i / 3) * 3 + (j / 3)].count(c);
    }

    bool solve(vector<vector<char>>& b, int i = 0, int j = 0, char c = '1'){
        if(j == 9){
            i++;
            j = 0;
        }

        if(i == 9) return true;
        if(c > '9') return false;

        if(b[i][j] != '.') return solve(b, i, j + 1);

        if(check(i, j, c)){
            put(b, i, j, c);

            if(solve(b, i, j + 1)) return true;

            remove(b, i, j, c);
        }

        return solve(b, i, j, c + 1);
    }

    void solveSudoku(vector<vector<char>>& b) {
        row.assign(9, {});
        col.assign(9, {});
        box.assign(9, {});

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++)
                if(b[i][j] != '.') put(b, i, j, b[i][j]);
        }

        solve(b);
    }
};
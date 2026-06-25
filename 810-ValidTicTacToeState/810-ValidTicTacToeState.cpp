// Last updated: 6/25/2026, 11:21:03 PM
class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        int x = 0;
        int o = 0;
        for(auto &s : b){
            for(auto &c : s){
                o += (c == 'O');
                x += (c == 'X');
            }
        }
        if(x > o + 1 || o > x) return false;
        bool o_win = false;
        bool x_win = false;

        // check rows and columns
        for(int i = 0; i < 3; i++){
            if(b[i][0] == b[i][1] && b[i][0] == b[i][2]){
                if(b[i][0] == 'O') o_win = true;
                if(b[i][0] == 'X') x_win = true;
            }
            if(b[0][i] == b[1][i] && b[0][i] == b[2][i]){
                if(b[0][i] == 'O') o_win = true;
                if(b[0][i] == 'X') x_win = true;
            }
        }

        // check diagonal
        if(b[0][0] == b[1][1] && b[0][0] == b[2][2]){
            if(b[0][0] == 'O') o_win = true;
            if(b[0][0] == 'X') x_win = true;
        }
        if(b[0][2] == b[2][0] && b[0][2] == b[1][1]){
            if(b[0][2] == 'O') o_win = true;
            if(b[0][2] == 'X') x_win = true;
        }
        if(o_win && x_win) return false;
        if(x_win && x != o + 1) return false;
        if(o_win && x != o) return false;
        return true;
    }
};
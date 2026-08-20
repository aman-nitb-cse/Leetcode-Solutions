// Last updated: 8/20/2026, 9:09:32 PM
class Solution {
public:
    vector<vector<int>> grid;
    void check(vector<vector<int>>& board, int row, int col) {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                int r = row + i;
                int c = col + j;
                if (r >= 0 && c >= 0 && r < board.size() &&
                    c < board[0].size()) {
                    if (board[r][c] == 1) {
                        count++;
                    }
                }
            }
        }
        if (board[row][col] == 1 && count < 2) {
            grid[row][col] = 0;
        } else if (board[row][col] == 1 && count > 3) {
            grid[row][col] = 0;
        } else if (board[row][col] == 0 && count == 3) {
            grid[row][col] = 1;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        grid = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                check(board, i, j);
            }
        }
        board = grid;
    }
};
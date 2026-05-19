class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> vis;
            for (int i = 0; i < 9; i++) {
                if(board[row][i] == '.') continue;
                if(vis.count(board[row][i])) return false;
                vis.insert(board[row][i]);
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<char> vis;
            for (int i = 0; i < 9; i++) {
                if(board[i][col] == '.') continue;
                if(vis.count(board[i][col])) return false;
                vis.insert(board[i][col]);
            }
        }

        for (int box = 0; box < 9; box++) {
            unordered_set<char> vis;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (box/3) * 3 + i;
                    int col = (box%3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (vis.count(board[row][col])) return false;
                    vis.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};

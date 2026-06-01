class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), box(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                
                int b = (r/3) * 3 + (c/3);

                if (row[r].count(val) || col[c].count(val) || box[b].count(val)) {
                    return false;
                }
                row[r].insert(val);
                col[c].insert(val);
                box[b].insert(val);
            }
        }
        return true;
    }
};

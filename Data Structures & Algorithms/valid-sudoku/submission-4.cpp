class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c< 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                
                int boxIdx = (r/3)*3 + (c/3);

                if (row[r].count(val) || col[c].count(val) || 
                box[boxIdx].count(val)) {
                    return false;
                } else {
                    row[r].insert(val);
                    col[c].insert(val);
                    box[boxIdx].insert(val);
                }
            }
        }
        return true;
    }
};

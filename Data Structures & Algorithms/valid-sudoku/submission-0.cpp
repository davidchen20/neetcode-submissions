class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // make a hash set for each row, col, and square
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<vector<unordered_set<char>>> squares(3, vector<unordered_set<char>>(3));

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                char c = board[row][col];

                if (c == '.') continue;

                if (rows[row].count(c)) return false;
                else rows[row].insert(c);

                if (cols[col].count(c)) return false;
                else cols[col].insert(c);

                if (squares[row / 3][col / 3].count(c)) return false;
                else squares[row / 3][col / 3].insert(c);
            }
        }

        return true;
    }
};

// row 012 col 012 -> square 0
// row 012 col 345 -> square 1
// row 012 col 678 -> square 2

// row 345 col 012 -> square 3

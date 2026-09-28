class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0]) {
                    int oldChar = board[row][col];
                    board[row][col] = '#';
                    if (dfs(board, directions, word, 1, row, col)) return true;
                    board[row][col] = oldChar;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<pair<int, int>>& directions, string& word, int idx, int row, int col) {
        if (idx == word.size()) return true;
        else {
            for (auto& [h, v] : directions) {
                int newRow = row + v;
                int newCol = col + h;

                bool rowInBounds = newRow >= 0 && newRow < board.size();
                bool colInBounds = newCol >= 0 && newCol < board[0].size();
                if (rowInBounds && colInBounds && board[newRow][newCol] != '#' && word[idx] == board[newRow][newCol]) {
                    int oldChar = board[newRow][newCol];
                    board[newRow][newCol] = '#';
                    if (dfs(board, directions, word, idx + 1, newRow, newCol)) return true;
                    board[newRow][newCol] = oldChar;
                }
            }
        }
        return false;
    }
};

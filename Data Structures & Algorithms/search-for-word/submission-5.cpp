class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        string path;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0]) {
                    int oldChar = board[row][col];
                    path.push_back(board[row][col]);
                    board[row][col] = '#';
                    if (dfs(board, directions, word, path, row, col)) return true;
                    board[row][col] = oldChar;
                    path.pop_back();
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<pair<int, int>>& directions, string& word, string& path, int row, int col) {
        if (path.size() == word.size()) return true;
        else {
            for (auto& [h, v] : directions) {
                int newRow = row + v;
                int newCol = col + h;

                bool rowInBounds = newRow >= 0 && newRow < board.size();
                bool colInBounds = newCol >= 0 && newCol < board[0].size();
                if (rowInBounds && colInBounds && board[newRow][newCol] != '#' && word[path.size()] == board[newRow][newCol]) {
                    int oldChar = board[newRow][newCol];
                    board[newRow][newCol] = '#';
                    path.push_back(board[newRow][newCol]);
                    if (dfs(board, directions, word, path, newRow, newCol)) return true;
                    path.pop_back();
                    board[newRow][newCol] = oldChar;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string path = "";

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                visited[row][col] = true;
                path.push_back(board[row][col]);
                if (dfs(board, visited, path, row, col, word)) return true;
                visited[row][col] = false;
                path.pop_back();
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& path, int row, int col, string& word) {
        if (path == word) return true;
        else {
            // check that current is on track to be word
            if (path.size() > word.size()) return false;

            // it is promising
            if (word.substr(0, path.size()) == path) {
                // visit down
                if (row + 1 < board.size() && !visited[row + 1][col]) {
                    visited[row + 1][col] = true;
                    path.push_back(board[row + 1][col]);
                    if (dfs(board, visited, path, row + 1, col, word)) return true;
                    visited[row + 1][col] = false;
                    path.pop_back();
                }

                // visit up
                if (row - 1 >= 0 && !visited[row - 1][col]) {
                    visited[row - 1][col] = true;
                    path.push_back(board[row - 1][col]);
                    if (dfs(board, visited, path, row - 1, col, word)) return true;
                    visited[row - 1][col] = false;
                    path.pop_back();
                }

                // visit right
                if (col + 1 < board[0].size() && !visited[row][col + 1]) {
                    visited[row][col + 1] = true;
                    path.push_back(board[row][col + 1]);
                    if (dfs(board, visited, path, row, col + 1, word)) return true;
                    visited[row][col + 1] = false;
                    path.pop_back();
                }

                // visit left
                if (col - 1 >= 0 && !visited[row][col - 1]) {
                    visited[row][col - 1] = true;
                    path.push_back(board[row][col - 1]);
                    if (dfs(board, visited, path, row, col - 1, word)) return true;
                    visited[row][col - 1] = false;
                    path.pop_back();
                }
            }
        }

        return false;
    }
};

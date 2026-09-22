class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // do a bfs and if you can't find a circle which is at the edge of the board, fill in everything in the path with x
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        // check the edges for O
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                visited[i][0] = true;
                dfs(board, visited, directions, i, 0);
            }

            if (board[i][board[0].size()-1] == 'O' && !visited[i][board[0].size()-1]) {
                visited[i][board[0].size()-1] = true;
                dfs(board, visited, directions, i, board[0].size()-1);
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                visited[0][i] = true;
                dfs(board, visited, directions, 0, i);
            }

            if (board[board.size()-1][i] == 'O' && !visited[board.size()-1][i]) {
                visited[board.size()-1][i] = true;
                dfs(board, visited, directions, board.size()-1, i);
            }
        }

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == 'O' && !visited[row][col]) board[row][col] = 'X';
            }
        }

    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<pair<int, int>>& directions, int row, int col) {
        for (auto& [drow, dcol] : directions) {
            int newRow = row + drow;
            int newCol = col + dcol;

            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && !visited[newRow][newCol] && board[newRow][newCol] == 'O') {
                visited[newRow][newCol] = true;
                dfs(board, visited, directions, newRow, newCol);
            }
        }
    }
};

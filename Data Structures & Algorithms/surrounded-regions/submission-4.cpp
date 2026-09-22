class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // do a bfs and if you can't find a circle which is at the edge of the board, fill in everything in the path with x
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        // check the edges for O
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(board, directions, i, 0);
            }

            if (board[i][board[0].size()-1] == 'O') {
                board[i][board[0].size()-1] = '#';
                dfs(board, directions, i, board[0].size()-1);
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '#';
                dfs(board, directions, 0, i);
            }

            if (board[board.size()-1][i] == 'O') {
                board[board.size()-1][i] = '#';
                dfs(board, directions, board.size()-1, i);
            }
        }

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == 'O') board[row][col] = 'X';
                if (board[row][col] == '#') board[row][col] = 'O';
            }
        }

    }

    void dfs(vector<vector<char>>& board, vector<pair<int, int>>& directions, int row, int col) {
        for (auto& [drow, dcol] : directions) {
            int newRow = row + drow;
            int newCol = col + dcol;

            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && board[newRow][newCol] == 'O') {
                board[newRow][newCol] = '#';
                dfs(board, directions, newRow, newCol);
            }
        }
    }
};

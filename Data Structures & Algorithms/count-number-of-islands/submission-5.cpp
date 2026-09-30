class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    count++;
                    dfs(grid, row, col);
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        // explore all directions
        for (auto& [h, v] : directions) {
            int newRow = row + v;
            int newCol = col + h;

            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1') {
                grid[newRow][newCol] = '0';
                dfs(grid, newRow, newCol);
            }
        }
    }
};
 
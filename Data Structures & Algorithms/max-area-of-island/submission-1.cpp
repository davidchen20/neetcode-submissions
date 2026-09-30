class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    int area = 1;
                    dfs(grid, row, col, area);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& area) {
        for (auto& [h, v] : directions) {
            int newRow = row + v;
            int newCol = col + h;

            bool validRow = newRow >= 0 && newRow < grid.size();
            bool validCol = newCol >= 0 && newCol < grid[0].size();

            if (validRow && validCol && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 0;
                area++;
                dfs(grid, newRow, newCol, area);
            }
        }
    }
};

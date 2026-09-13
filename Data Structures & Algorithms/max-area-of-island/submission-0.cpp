class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // each time you find an unvisited 1, dfs to find the size of it
        // return max area

        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    // find all the other ones and get maxARea
                    int area = 0;
                    dfs(grid, row, col, area);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& len) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if (grid[row][col] == 0) return;

        // mark as visited
        grid[row][col] = 0;
        len++;

        // up
        dfs(grid, row - 1, col, len);

        // down
        dfs(grid, row + 1, col, len);

        // left
        dfs(grid, row, col - 1, len);

        // right
        dfs(grid, row, col + 1, len);
    }
};

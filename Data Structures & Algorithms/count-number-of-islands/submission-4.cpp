class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        // iterate through and once you find an unexplored 1, dfs until you can't anymore        

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // dfs
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j);
                }

                // mark as visited 
                visited[i][j] = true;
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (visited[i][j]) return;
        if (grid[i][j] != '1') return;

        visited[i][j] = true;

        // go left
        dfs(grid, visited, i, j - 1);

        // go right
        dfs(grid, visited, i, j + 1);

        // go up
        dfs(grid, visited, i - 1, j);

        // go down
        dfs(grid, visited, i + 1, j);
    }
};

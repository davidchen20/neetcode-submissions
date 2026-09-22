class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // from each edge, dfs upwards
        // if a square is visisted both by pacfici and atlantic, then it is an answer
        vector<vector<bool>> pacificVisited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticVisited(heights.size(), vector<bool>(heights[0].size(), false));

        // dfs all right vertical atlantic
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, atlanticVisited, i, heights[0].size() - 1);
        }

        // dfs all bottom horizontal atlantic
        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, atlanticVisited, heights.size()-1, i);
        }

        // dfs all right vertical atlantic
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, pacificVisited, i, 0);
        }

        // dfs all bottom horizontal atlantic
        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, pacificVisited, 0, i);
        }

        vector<vector<int>> ans;
        for (int row = 0; row < heights.size(); row++) {
            for (int col = 0; col < heights[0].size(); col++) {
                if (atlanticVisited[row][col] && pacificVisited[row][col]) ans.push_back({row, col});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col) {
        visited[row][col] = true;

        // up
        if (row - 1 >= 0 && !visited[row-1][col] && heights[row-1][col] >= heights[row][col]) dfs(heights, visited, row - 1, col);

        // down
        if (row + 1 < heights.size() && !visited[row+1][col] && heights[row+1][col] >= heights[row][col]) dfs(heights, visited, row + 1, col);

        // left
        if (col - 1 >= 0 && !visited[row][col - 1] && heights[row][col-1] >= heights[row][col]) dfs(heights, visited, row, col - 1);

        // right
        if (col + 1 < heights[0].size() && !visited[row][col + 1] && heights[row][col+1] >= heights[row][col]) dfs(heights, visited, row, col + 1);
    }

};

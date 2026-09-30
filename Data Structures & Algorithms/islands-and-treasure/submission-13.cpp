class Solution {
public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // bfs out from all of them
        int level = 1;
        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                pair<int, int> poi = q.front();
                q.pop();

                for (auto& [h, v] : directions) {
                    int newRow = poi.first + v;
                    int newCol = poi.second + h;

                    bool validRow = newRow >= 0 && newRow < grid.size();
                    bool validCol = newCol >= 0 && newCol < grid[0].size();

                    if (validRow && validCol && grid[newRow][newCol] == INF) {
                        grid[newRow][newCol] = level;
                        q.push({newRow, newCol});
                    }
                }
            }

            level++;
        }
    }
};

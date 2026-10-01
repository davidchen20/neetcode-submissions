class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshFruits = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) freshFruits++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int minute = 0;
        while (!q.empty() && freshFruits > 0) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                pair<int, int> poi = q.front();
                q.pop();
                for (auto& [h, v] : directions) {
                    int newRow = poi.first + v;
                    int newCol = poi.second + h;

                    bool validRow = newRow >= 0 && newRow < grid.size();
                    bool validCol = newCol >= 0 && newCol < grid[0].size();

                    if (validRow && validCol && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshFruits--;
                    }
                }
            }
            minute++;
        }

        return freshFruits > 0 ? -1 : minute;
    }
};

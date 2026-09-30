class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // count the number of fresh fruit
        // bfs out from the rotten fruit
            // if at the end, the queue is empty and fresh fruits > 0, return -1
        // minutes can be thought og as levels

        int freshFruits = 0;
        queue<pair<int, int>> q;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) freshFruits++;
                else if (grid[row][col] == 2) q.push({row, col});
            }
        }
        
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        int level = 0;
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
                        freshFruits--;
                        q.push({newRow, newCol});
                    }
                }
            }

            level++;
        }

        return freshFruits == 0 ? level : -1;
    }
};

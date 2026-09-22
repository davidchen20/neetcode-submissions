class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // push all treasure chests into a queue and then bfs all at the same time. the level is the distance
        queue<pair<int, int>> q;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 0) q.push({row, col});
            }
        } 

        int level = 1;
        int INF = 2147483647;
        // bfs on all the treasures
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                pair<int, int> poi = q.front();
                q.pop();

                // up down left right
                if (poi.first - 1 >= 0 && grid[poi.first-1][poi.second] == INF) {
                    grid[poi.first - 1][poi.second] = level;
                    q.push({poi.first-1, poi.second});
                } 
                if (poi.first + 1 < grid.size() && grid[poi.first+1][poi.second] == INF) {
                    grid[poi.first + 1][poi.second] = level;
                    q.push({poi.first+1, poi.second});
                }
                if (poi.second - 1 >= 0 && grid[poi.first][poi.second - 1] == INF) {
                    grid[poi.first][poi.second - 1] = level;
                    q.push({poi.first, poi.second - 1});
                }
                if (poi.second + 1 < grid[0].size() && grid[poi.first][poi.second + 1] == INF) {
                    grid[poi.first][poi.second+1] = level;
                    q.push({poi.first, poi.second + 1});
                }
            }

            level++;
        }
    }
};

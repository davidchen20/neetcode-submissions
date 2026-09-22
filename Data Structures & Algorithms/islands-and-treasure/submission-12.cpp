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

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        // bfs on all the treasures
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                pair<int, int> poi = q.front();
                q.pop();

                for (auto& [h, v] : directions) {
                    int nh = poi.first + h;
                    int nv = poi.second + v;

                    if (nh >= 0 && nh < grid.size() && nv >= 0 && nv < grid[0].size() && grid[nh][nv] == INF) {
                        grid[nh][nv] = level;
                        q.push({nh, nv});
                    }
                }
            }

            level++;
        }
    }
};

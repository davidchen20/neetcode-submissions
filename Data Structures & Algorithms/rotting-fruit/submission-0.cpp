class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // each level will be one minute
        // multi source

        queue<pair<int, int>> q;

        int rotten = 0;
        int fresh = 0;
        // add all the rotten fruit to the queue
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                } else if (grid[row][col] == 1) fresh++;
            }
        }

        // bfs from all of them

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int level = 0;
        while (fresh > 0 && !q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                pair<int, int> poi = q.front();
                q.pop();

                for (auto& [h, v] : directions) {
                    int nh = poi.first + h;
                    int nv = poi.second + v;

                    if (nh >= 0 && nh < grid.size() && nv >= 0 && nv < grid[0].size() && grid[nh][nv] == 1) {
                        grid[nh][nv] = 2;
                        q.push({nh, nv});
                        fresh--;
                    }
                }
            }

            level++;
        }

        return fresh == 0 ? level : -1;
    }
};

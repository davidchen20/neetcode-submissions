class Solution {
    struct Vertex {
        bool visited = false;
        int minDistance = INT_MAX;
        int cameFrom;
    };
public:
    int distance(vector<int>& v1, vector<int>& v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Vertex> vertices(points.size());
        vertices[0].minDistance = 0;
        for (int i = 0; i < vertices.size(); i++) {
            int voi = -1;
            for (int j = 0; j < vertices.size(); j++) {
                if (!vertices[j].visited && (voi == -1 || vertices[j].minDistance < vertices[voi].minDistance)) {
                    voi = j;
                }
            }

            vertices[voi].visited = true;

            for (int j = 0; j < vertices.size(); j++) {
                if (!vertices[j].visited) {
                    int manhattanDistance = distance(points[voi], points[j]);
                    if (manhattanDistance < vertices[j].minDistance) {
                        vertices[j].minDistance = manhattanDistance;
                        vertices[j].cameFrom = voi;
                    }
                }
            }

        }

        int minCost = 0;
        for (int i = 0; i < vertices.size(); i++) {
            minCost += vertices[i].minDistance;
        }

        return minCost;
    }
};

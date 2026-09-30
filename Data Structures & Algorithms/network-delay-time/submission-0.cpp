class Solution {
public:
    struct Vertex {
        bool visited = false;
        int minDistance = INT_MAX;
        int cameFrom;
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<Vertex> vertices(n);
        unordered_map<int, vector<pair<int, int>>> adjList;

        for (int i = 0; i < times.size(); i++) {
            adjList[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }

        vertices[k-1].minDistance = 0;

        for (int i = 0; i < n; i++) {
            int voi = -1;
            // look for the vertex with the smallest distance
            for (int j = 0; j < n; j++) {
                if (!vertices[j].visited && (voi == -1 || vertices[j].minDistance < vertices[voi].minDistance)) voi = j;
            }

            // mark it as visited
            vertices[voi].visited = true;

            if (vertices[voi].minDistance == INT_MAX) break;
            // update the min distances
            vector<pair<int, int>>& adjEdges = adjList[voi];
            for (auto& edge : adjEdges) {
                if (edge.second + vertices[voi].minDistance < vertices[edge.first].minDistance) {
                    vertices[edge.first].minDistance = edge.second + vertices[voi].minDistance;
                    vertices[edge.first].cameFrom = voi;
                }
            }
        }

        int maxDistance = 0;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].minDistance == INT_MAX) return -1;
            maxDistance = max(maxDistance, vertices[i].minDistance);
        }

        return maxDistance;
    }
};

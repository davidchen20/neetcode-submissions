class Solution {
    struct Vertex {
        bool visited = false;
        int minDistance = INT_MAX;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<Vertex> vertices(n);
        vector<vector<pair<int,int>>> adjList(n);

        for (int i = 0; i < times.size(); i++) {
            vector<int>& edge = times[i];
            adjList[edge[0]-1].push_back({edge[1]-1, edge[2]});
        }

        vertices[k-1].minDistance = 0;

        for (int i = 0; i < n; i++) {
            int voi = -1;
            for (int j = 0; j < n; j++) {
                if (!vertices[j].visited && (voi == -1 || vertices[j].minDistance < vertices[voi].minDistance)) voi = j;
            }

            vertices[voi].visited = true;

            if (vertices[voi].minDistance == INT_MAX) return -1;

            vector<pair<int, int>>& edges = adjList[voi];
            for (auto& edge : edges) {
                int newDistance = vertices[voi].minDistance + edge.second;
                if (newDistance < vertices[edge.first].minDistance) vertices[edge.first].minDistance = newDistance;
            }
        }

        int maxDistance = 0;
        for (int i = 0; i < vertices.size(); i++) {
            maxDistance = max(maxDistance, vertices[i].minDistance);
        }

        return maxDistance;
        
    }
};

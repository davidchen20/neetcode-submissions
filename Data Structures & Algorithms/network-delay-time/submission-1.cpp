class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distances(n, INT_MAX);

        distances[k-1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        unordered_map<int, vector<pair<int, int>>> adjList;
        for (int i = 0; i < times.size(); i++) {
            adjList[times[i][0]-1].emplace_back(times[i][1]-1, times[i][2]);
        }

        pq.push({k-1, 0});
        while (!pq.empty()) {
            // get the node with the smallest distance 
            int node = pq.top().first;
            int weight = pq.top().second;
            pq.pop();

            // handle duplicates
            if (weight > distances[node]) continue;

            // do explorations
            vector<pair<int, int>>& edges = adjList[node];
            for (auto& edge : edges) {
                if (distances[node] + edge.second < distances[edge.first]) {
                    pq.push({edge.first, distances[node] + edge.second});
                    distances[edge.first] = distances[node] + edge.second;
                }
            }
        }

        int maxDistance = 0;
        for (int i = 0; i < distances.size(); i++) {
            maxDistance = max(maxDistance, distances[i]);
        }

        return maxDistance == INT_MAX ? -1 : maxDistance;
    }
};

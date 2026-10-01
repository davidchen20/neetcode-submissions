class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < times.size(); i++) {
            vector<int>& edge = times[i];
            adjList[edge[0]-1].emplace_back(edge[1]-1, edge[2]);
        }

        vector<int> distances(n, INT_MAX);

        distances[k-1] = 0;
        pq.push({0, k-1});
        while (!pq.empty()) {
            pair<int, int> voi = pq.top();
            pq.pop();

            if (voi.first > distances[voi.second]) continue;
            vector<pair<int, int>> neighbors = adjList[voi.second];

            for (auto& neighbor : neighbors) {
                int weightToNeighbor = neighbor.second;
                if (distances[voi.second] + weightToNeighbor < distances[neighbor.first]) {
                    distances[neighbor.first] = distances[voi.second] + weightToNeighbor;
                    pq.push({distances[neighbor.first], neighbor.first});
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

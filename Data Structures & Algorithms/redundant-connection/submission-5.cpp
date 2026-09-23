class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 1. locate the cycle
        // 2. find the edge that appears last in edges

        unordered_map<int, vector<int>> m;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            m[u].push_back(v);
            m[v].push_back(u);
        }

        vector<bool> visited(edges.size()+1, false);
        unordered_set<int> cycle;
        int cycleStart = -1;
        dfs(m, visited, cycle, 1, -1, cycleStart);

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (cycle.count(u) && cycle.count(v)) return {u, v};
        }
        return {};

        // find the edge that appears last
    }

    bool dfs(unordered_map<int, vector<int>>& m, vector<bool>& visited, unordered_set<int>& cycle, int current, int cameFrom, int& cycleStart) {
        if (visited[current]) {
            cycleStart = current;
            return true;
        }

        visited[current] = true;
        vector<int>& neighbors = m[current];
        for (auto neighbor : neighbors) {
            if (neighbor != cameFrom && dfs(m, visited, cycle, neighbor, current, cycleStart)) {
                if (cycleStart != -1) cycle.insert(current);
                if (current == cycleStart) cycleStart = -1;

                return true;
            }
        }

        return false;
    }
};

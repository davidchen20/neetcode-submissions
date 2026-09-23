class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 1. locate the cycle
        // 2. find the edge that appears last in edges

        unordered_map<int, vector<int>> m;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // can i already get to v from u?
            vector<bool> visited(edges.size()+1, false);
            if (dfs(m, visited, u, v, -1)) return {u, v};

            m[u].push_back(v);
            m[v].push_back(u);
        }

        return {};

        // find the edge that appears last
    }

    bool dfs(unordered_map<int, vector<int>>& m, vector<bool>& visited, int current, int target, int cameFrom) {
        if (current == target) return true;
        visited[current] = true;
        vector<int>& neighbors = m[current];
        for (auto& neighbor : neighbors) {
            if (neighbor != cameFrom && !visited[neighbor] && dfs(m, visited, neighbor, target, current)) return true; 
        }

        return false;
    }
};

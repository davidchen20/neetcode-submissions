class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;

        for (auto& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }

        vector<bool> seen(n, false);

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                components++;
                dfs(m, seen, i);
            }
        }

        return components;
    }

    void dfs(unordered_map<int, vector<int>>& m, vector<bool>& seen, int node) {
        if (seen[node]) return;
        seen[node] = true;
        vector<int>& neighbors = m[node];
        for (auto& neighbor : neighbors) {
            if (!seen[neighbor]) dfs(m, seen, neighbor);
        }
    }
};

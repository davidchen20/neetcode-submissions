class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // a tree has no cycles
        // adjacency list!!!
        unordered_map<int, vector<int>> m;
        for (auto& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> path;

        // only need to check the first node since we should be able to get to every node
        if (hasCycle(m, path, -1, 0)) return false;

        // checking if the graph is connected
        return path.size() == n;
    }

    bool hasCycle(unordered_map<int, vector<int>>& m, unordered_set<int>& path, int cameFrom, int node) {
        if (path.count(node)) return true;
        path.insert(node);

        vector<int>& neighbors = m[node];
        for (auto& neighbor : neighbors) {
            if (neighbor != cameFrom && hasCycle(m, path, node, neighbor)) return true; 
        }

        // we dont need to remove from path since we are in an undirected graph

        return false;
    }
};

class Solution {

    class UnionFind {
        public:
            vector<int> parent;

            UnionFind(int n) {
                parent.resize(n);
                for (int i = 0; i < parent.size(); i++) {
                    parent[i] = i;
                }
            }
            int find(int node) {
                if (parent[node] != node) parent[node] = find(parent[node]);

                return parent[node]; 
            }

            bool unionSets(int node1, int node2) {
                int root1 = find(node1);
                int root2 = find(node2);

                // would create a cycle
                if (root1 == root2) return false;
                parent[root1] = root2;

                return true;
            }
    };
public:
    struct Edge {
        int A;
        int B;
        int weight;
    };

    struct Comparator {
        bool operator()(Edge& e1, Edge& e2) {
            if (e1.weight != e2.weight) return e1.weight < e2.weight;
            if (e1.A != e2.A) return e1.A < e2.A;
            return e1.B < e2.B;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(i, j, distance);
            }
        }

        sort(edges.begin(), edges.end(), Comparator());

        UnionFind uf(points.size());
        int edgesAdded = 0;
        int minCost = 0;

        for (const auto& edge : edges) {
            if (uf.unionSets(edge.A, edge.B)) {
                edgesAdded++;
                minCost += edge.weight;
            }

            if (edgesAdded == points.size() - 1) break;
        }

        return minCost;
    }
};

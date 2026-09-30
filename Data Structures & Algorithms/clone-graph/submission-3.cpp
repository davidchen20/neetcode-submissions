/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (m.count(node)) return m[node];
        Node* deepCopy;
        if (m.find(node) == m.end()) {
            deepCopy = new Node(node->val);
            m[node] = deepCopy;
        } else deepCopy = m[node];

        for (int i = 0; i < node->neighbors.size(); i++) {
            // Node* neighborCopy;
            // if (m.find(node->neighbors[i]) == m.end()) neighborCopy = cloneGraph(node->neighbors[i]);
            // else neighborCopy = m[node->neighbors[i]];

            deepCopy->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }

        return deepCopy;
    }
};

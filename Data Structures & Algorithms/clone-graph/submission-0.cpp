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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> deepCopy;

        return helper(node, deepCopy);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& deepCopy) {
        auto it = deepCopy.find(node);
        if (it != deepCopy.end()) return it->second;
        // have a map with each of the nodes. if it doesn,t exist in vector, create a new node
        
        Node* deepRoot = new Node(node->val);
        deepCopy[node] = deepRoot;

        vector<Node*>& neighbors = node->neighbors;

        for (auto& neighbor : neighbors) {
            deepRoot->neighbors.push_back(helper(neighbor, deepCopy));
        }

        return deepRoot;
        // deep copy root
        // deep copy each of its neighbors
        // loop until everything you get one where all the neighbors are already deep copied
    }
};

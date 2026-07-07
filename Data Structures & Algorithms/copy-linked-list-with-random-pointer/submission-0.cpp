/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Iteration 1: create all nodes and map original nodes to deep copy ones
        // Iteration 2: connect random pointers and connect next pointers 

        unordered_map<Node*, Node*> m;
        Node* current = head;

        // Iteration 1
        while (current) {
            // Create a deep copy of the current node
            Node* node = new Node(current->val);

            m[current] = node;

            current = current->next;
        }

        // Iteration 2
        current = head;
        while (current) {
            Node* noi = m[current];

            noi->next = m[current->next];
            noi->random = m[current->random];

            current = current->next;
        }

        return m[head];
    }
};

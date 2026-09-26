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
        // have a hashmap containing the original mapped to the deep copy

        Node* dummy = new Node(0);
        Node* current = dummy;
        unordered_map<Node*, Node*> m;
        while (head) {
            // is there a deep copy available
            auto it = m.find(head);
            if (it == m.end()) {
                Node* deepCopy = new Node(head->val);
                m[head] = deepCopy;
            }
            Node* deepCopy = m[head];

            // set the random
            it = m.find(head->random);
            if (it == m.end()) {
                Node* deepCopy;
                if (head->random) deepCopy = new Node(head->random->val);
                else deepCopy = nullptr;
                m[head->random] = deepCopy;
            }

            deepCopy->random = m[head->random];

            // set the next
            it = m.find(head->next);
            if (it == m.end()) {
                Node* deepCopy;
                if (head->next) deepCopy = new Node(head->next->val);
                else deepCopy = nullptr;
                m[head->next] = deepCopy;
            }

            deepCopy->next = m[head->next];

            current->next = deepCopy;

            current = current->next;
            head = head->next;
        }

        Node* ans = dummy->next;
        delete dummy;

        return ans;
    }
};

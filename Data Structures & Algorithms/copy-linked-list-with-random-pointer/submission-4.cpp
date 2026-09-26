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
        // make a copy of each node next to itself
        Node* current = head;
        while (current) {
            Node* deepCopy = new Node(current->val);
            Node* tmp = current->next;
            current->next = deepCopy;
            deepCopy->next = tmp;

            current = tmp;
        }

        Node* dummy = new Node(0);
        current = dummy;

        while (head) {
            // get the node itself
            Node* node = head->next;

            if (!head->next) node->next = nullptr;
            else node->next = head->next->next;
            
            if (!head->random) node->random = nullptr;
            else node->random = head->random->next;

            current->next = node;
            current = current->next;
            head = head->next->next;
        }

        Node* ans = dummy->next;
        delete dummy;

        return ans;
    }
};

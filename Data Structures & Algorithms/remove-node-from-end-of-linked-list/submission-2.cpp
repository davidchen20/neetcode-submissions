/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find size of linked list
        // size - n = locaiton of node to remove
        // go to that node and detach it

        int size = 0;
        ListNode* current = head;
        while (current) {
            size++;
            current = current->next;
        }

        if (size < 2) return nullptr;
        if (size == n) return head->next;

        int counts = size - n;
        ListNode* prev = head;
        current = head;
        for (int i = 0; i < counts; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;

        return head;
    }
};

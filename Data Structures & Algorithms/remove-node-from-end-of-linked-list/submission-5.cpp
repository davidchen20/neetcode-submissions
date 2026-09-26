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
        // calculate size of list
        ListNode* current = head;
        int size = 0;

        while (current) {
            size++;
            current = current->next;
        }

        int idx = size - n;
        current = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < idx; i++) {
            prev = current;
            current = current->next;
        }

        if (current == head) {
            ListNode* newHead = head->next;
            delete current;
            return newHead;
        } else {
            ListNode* tmp = current->next;
            prev->next = tmp;
            delete current;
            return head;
        }
    }
};

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
        // start a right pointer n nodes from start
        // put left pointer at one before head
        // move both until right hits nullptr
        ListNode* prev = nullptr;
        ListNode* l = head;
        ListNode* r = head;
        for (int i = 0; i < n; i++) {
            r = r->next;
        }

        while (r) {
            prev = l;
            l = l->next;
            r = r->next;
        }

        if (!prev) return l->next;

        prev->next = l->next;
        
        return head;

    }
};

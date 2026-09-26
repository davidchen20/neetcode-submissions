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
        // space out the pointers by n
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        ListNode* prev = nullptr;

        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        // slow has nth node from end
        if (slow == head) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        } else {
            prev->next = slow->next;
            delete slow;
            return head;
        }
    }
};

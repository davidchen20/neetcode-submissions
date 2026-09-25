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
    void reorderList(ListNode* head) {
        // find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // sever the link
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse linked list from slow to end
        ListNode* prev = nullptr;
        while(second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // merge them
        while (prev) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = prev->next;

            head->next = prev;
            prev->next = tmp1;

            prev = tmp2;
            head = tmp1;
        }
    }
};

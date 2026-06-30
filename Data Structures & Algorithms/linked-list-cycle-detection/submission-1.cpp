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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool first = true;

        while (fast) {
            if (slow == fast && !first) return true;
            first = false;
            if (!slow->next) return false;
            slow = slow->next;
            if (!fast->next) return false;
            fast = fast->next;
            if (!fast->next) return false;
            fast = fast->next;
        }

        return false;
    }
};

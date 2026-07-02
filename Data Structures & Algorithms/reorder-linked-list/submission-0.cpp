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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfHead = slow->next;
        slow->next = nullptr; 

        ListNode* curr = secondHalfHead;
        ListNode* prev2 = nullptr;
        while (curr) {
            ListNode* next2 = curr->next;
            curr->next = prev2;
            prev2 = curr;
            curr = next2;
        }
        secondHalfHead = prev2;

        // 5. Interleave the two halves (Your logic here is also perfect)
        ListNode* ptr1 = head;
        ListNode* ptr2 = secondHalfHead;

        while (ptr2) {
            ListNode* ptr1Next = ptr1->next;
            ListNode* ptr2Next = ptr2->next;
            
            ptr1->next = ptr2;
            ptr2->next = ptr1Next;

            ptr1 = ptr1Next;
            ptr2 = ptr2Next;
        }
    }
};

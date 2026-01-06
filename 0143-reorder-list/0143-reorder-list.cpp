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
        if (!head || !head->next)
            return;

        // middle find
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow point middle

        // reverse start from slow+1

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        slow->next = nullptr;

        while (curr) {
            ListNode* newtemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newtemp;
        }

        // merge

        ListNode* first = head;  // 1
        ListNode* second = prev; // 5

        while (second) {
            ListNode* temp1 = first->next;  // 2
            ListNode* temp2 = second->next; // null

            first->next = second;
            second->next = temp1;

            // temp1=2
            // first=1
            first = temp1;
            second = temp2;
        }
    }
};
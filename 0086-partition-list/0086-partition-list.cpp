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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        //  here i want to make dmmy list for store data new
        ListNode* dummy = new ListNode(0);
        ListNode* dummypoint = dummy;

        ListNode* dummy2 = new ListNode(0);
        ListNode* dummypoint2 = dummy2;

        while (curr != NULL) {
            if (curr->val < x) {
                dummypoint->next = new ListNode(curr->val);
                dummypoint = dummypoint->next;

            } else {
                dummypoint2->next = new ListNode(curr->val);
                dummypoint2 = dummypoint2->next;
            }
            curr = curr->next;
        }

        dummypoint->next = dummy2->next;

        return dummy->next;
    }
};
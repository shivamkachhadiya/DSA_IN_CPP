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
        
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (count == 1 && n == 1) return NULL;
        int target = count - n;
        if (target == 0) {
            return head->next;  // ✓ Return new head when deleting first node
        }
        int i = 0;
        ListNode* deletePtr = head;
        while (i != target - 1) {
            deletePtr = deletePtr->next;
            i++;
        }
        deletePtr->next = deletePtr->next->next;
        return head;
    }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        
        while (tmp != nullptr && tmp->next != nullptr) {
            if (tmp->val == tmp->next->val) {
                // Skip the duplicate node
                tmp->next = tmp->next->next;
            } else {
                // Move to next node only if no deletion occurred
                tmp = tmp->next;
            }
        }
        
        return head;
    }
};

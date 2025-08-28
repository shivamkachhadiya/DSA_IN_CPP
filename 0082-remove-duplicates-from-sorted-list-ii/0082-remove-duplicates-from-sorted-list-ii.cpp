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
        if (!head) return nullptr;

        // dummy node to handle cases where head itself is duplicate
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            // check if current node has duplicates
            if (head->next && head->val == head->next->val) {
                // skip all nodes with this value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // connect prev to the node after duplicates
                prev->next = head->next;
            } else {
                // no duplicate → move prev forward
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

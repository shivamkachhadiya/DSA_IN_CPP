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
    ListNode* middleNode(ListNode* head) {
        // int count = 0;
        // ListNode* curr = head;

        // while (curr != nullptr) {
        //     count++;
        //     curr = curr->next;
        // }

        // int midPos = count / 2;
        // curr = head;

        // while (midPos) {
        //     midPos--;
        //     curr = curr->next;
        // }

        // return curr;
//------------------------------------------------------------
        // Initialize the slow pointer to the head.
        ListNode* slow = head;

        // Initialize the fast pointer to the head.
        ListNode* fast = head;

        // Traverse the linked list using the
        // Tortoise and Hare algorithm.
        while (fast != NULL && fast->next != NULL) {
            // Move slow one step.
            slow = slow->next;
            // Move fast two steps.
            fast = fast->next->next;
        }

        // Return the slow pointer,
        // which is now at the middle node.
        return slow;
    }
};

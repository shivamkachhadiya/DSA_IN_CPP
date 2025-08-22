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
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: if list is empty, has only one node, or k is 0 → no rotation needed
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Count the total number of nodes in the list
        int count = 1;
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            count++;
            curr = curr->next;
        }

        // Step 2: Connect the last node to the head to make it circular
        curr->next = head;

        // Step 3: Calculate the actual number of rotations needed
        // If k > count, rotating k times is same as rotating k % count times
        k = k % count;

        // Step 4: Calculate the number of steps to reach the new tail
        // New tail is at (count - k)th position from start
        int target = count - k;

        // Step 5: Move to the (count - k)th node (the new tail)
        int track = 1;
        curr = head;
        while (track != target) {
            curr = curr->next;
            track++;
        }

        // Step 6: Set new head to the next node and break the circle
        head = curr->next;
        curr->next = NULL;

        // Step 7: Return the new head
        return head;
    }
};
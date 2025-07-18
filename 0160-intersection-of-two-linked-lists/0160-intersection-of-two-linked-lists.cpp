/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Edge case: if either head is null, no intersection
        if (headA == NULL || headB == NULL)
            return NULL;

        // Start two pointers at the heads of both lists
        ListNode* h1 = headA;
        ListNode* h2 = headB;

        // Loop until the pointers meet
        while (h1 != h2) {
            // If h1 reaches the end, move it to headB
            if (h1 == NULL)
                h1 = headB;
            else
                h1 = h1->next;

            // If h2 reaches the end, move it to headA
            if (h2 == NULL)
                h2 = headA;
            else
                h2 = h2->next;
        }

        // h1 and h2 are equal at intersection or both NULL (no intersection)
        return h1;
    }
};

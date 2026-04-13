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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* newHead = new ListNode(0);
        ListNode* temp3 = newHead;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int a = 0;
            int b = 0;
            if (temp1 != NULL) {
                a = temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != NULL) {
                b = temp2->val;
                temp2 = temp2->next;
            }
            int c = a + b + carry;
            int ans = c % 10;
            carry = c / 10;

            temp3->next = new ListNode(ans);
            temp3 = temp3->next;
           
        }
        return newHead->next;
    }
};
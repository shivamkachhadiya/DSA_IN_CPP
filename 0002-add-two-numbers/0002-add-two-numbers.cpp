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
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* newHead=new ListNode(0);
        ListNode* new_temp=newHead;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL || carry!=0){

            int n1=0;
            if(temp1!=NULL)n1=temp1->val;
            int n2=0;
            if(temp2!=NULL)n2=temp2->val;

            int sum = n1 + n2 + carry;
            int last_digit = sum % 10;  // ✓ Units digit
            carry = sum / 10;      // ✓ Carry to next position

            new_temp->next=new ListNode(last_digit);
            if(temp1 != NULL) temp1=temp1->next;
            if(temp2 != NULL) temp2=temp2->next;
            new_temp=new_temp->next;
        }
        return newHead->next;
    }
};

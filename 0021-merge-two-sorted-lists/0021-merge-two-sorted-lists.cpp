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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newNode = new ListNode(0);
        ListNode* newPtr = newNode;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                newPtr->next = new ListNode(temp1->val);
                newPtr = newPtr->next;
                temp1 = temp1->next;
            } else {
                newPtr->next = new ListNode(temp2->val);
                newPtr = newPtr->next;

                temp2 = temp2->next;
            }
        }
        while(temp1!=nullptr){
            newPtr->next=new ListNode(temp1->val);
            newPtr=newPtr->next;
            temp1=temp1->next;
        }

        while(temp2!=nullptr){
            newPtr->next=new ListNode(temp2->val);
                        newPtr=newPtr->next;
            temp2=temp2->next;
        }
        return newNode->next;
  }
};
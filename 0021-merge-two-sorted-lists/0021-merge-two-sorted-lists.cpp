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
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* newDummyLinkList=new ListNode(0);
        ListNode* tempPTR=newDummyLinkList;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                tempPTR->next=new ListNode(temp1->val);
                tempPTR=tempPTR->next;
                temp1=temp1->next;
            }else{
                tempPTR->next=new ListNode(temp2->val);
                tempPTR=tempPTR->next;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            tempPTR->next=new ListNode(temp1->val);
            tempPTR=tempPTR->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            tempPTR->next=new ListNode(temp2->val);
            tempPTR=tempPTR->next;
            temp2=temp2->next;
        }
        return newDummyLinkList->next;
    }
};

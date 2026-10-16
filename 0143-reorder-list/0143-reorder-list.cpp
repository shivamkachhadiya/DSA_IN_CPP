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
    void reorderList(ListNode* head) {
        if(head->next==NULL||head->next->next==NULL)return;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* second=slow->next;
        slow->next=NULL;

        ListNode* prev=NULL;
        ListNode* curr=second;

        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* first=head;
        second=prev;
        while(second!=NULL){
            ListNode* next1=first->next;
            ListNode* next2=second->next;

            first->next=second;
            second->next=next1;

            first=next1;
            second=next2;
        }
    }
};
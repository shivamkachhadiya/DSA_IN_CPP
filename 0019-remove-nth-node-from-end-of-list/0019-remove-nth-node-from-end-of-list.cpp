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
    int count(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return nullptr;
        int num_of_nodes=count(head);
        int target=num_of_nodes-n;
        if(target==0){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        ListNode* temp=head;
        while(target-1){
            temp=temp->next;
            target--;            
        }
        ListNode* nodeToDelete=temp->next;
        temp->next=nodeToDelete->next;
        delete nodeToDelete;
        return head;
    }
};
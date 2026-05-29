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
    ListNode* reverse_nodes(ListNode* start,ListNode* end){
        ListNode* curr=start;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=end){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        int temp = k;
        while (temp && end != NULL) {
            end = end->next;
            temp--;
        }
        if (temp > 0) return head;

        //till now pointer is set

        // now main work start that is reverse

       ListNode* newNode=reverse_nodes(start,end);
       start->next=reverseKGroup(end,k);
       return newNode;
    }
};

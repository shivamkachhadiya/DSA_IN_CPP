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
    ListNode* deleteMiddle(ListNode* head) {

        // if (head == nullptr || head->next == nullptr)
        //     return nullptr;

        // //count nodes
        // int count=0;
        // ListNode* tmp=head;
        // while(tmp!=NULL){
        //     count++;
        //     tmp=tmp->next;
        // }
        // tmp=head;
        // int mid=count/2;
        // int track=1;
        // while(track!=mid){
        //     track++;
        //     tmp=tmp->next;
        // }
        // tmp->next=tmp->next->next;
        // return head;

        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // slow is the middle node
        prev->next = slow->next;
        return head;
    }
};
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
    int countnodes(auto head) {
        auto temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        // int n = countnodes(head);
        // if(head->next==nullptr)return nullptr;
        // int target = n / 2;
        // int index = 0;
        // auto tmp = head;
        // while (index != target - 1) {
        //     index++;
        //     tmp = tmp->next;
        // }
        // tmp->next=tmp->next->next;
        // return head;
         if(head->next==nullptr)return nullptr;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        auto slow=head;
        auto fast=head;
        auto prev=dummy;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};
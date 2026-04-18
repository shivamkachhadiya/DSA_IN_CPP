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
    ListNode* middleNode(ListNode* head) {
        ListNode* slw=head;
        ListNode* fst=head;
        while(slw!=NULL && fst!=NULL && fst->next!=NULL){
            slw=slw->next;
            fst=fst->next->next;
        }
        return slw;
    }
};
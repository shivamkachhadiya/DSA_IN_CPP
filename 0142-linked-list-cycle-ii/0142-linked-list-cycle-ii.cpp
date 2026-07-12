/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slw=head;
        ListNode* fst=head;
        while(fst!=nullptr&&fst->next!=nullptr){
            slw=slw->next;
            fst=fst->next->next;
            if(slw==fst){
                fst=head;
                while(slw!=fst){
                    slw=slw->next;
                    fst=fst->next;
                }
                return slw;
            }
        }
        return nullptr;
    }
};
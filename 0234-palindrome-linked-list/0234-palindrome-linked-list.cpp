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
 #include <stack>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
         stack<int> s;
         ListNode* tmp=head;
         while(tmp!=NULL){
            s.push(tmp->val);
            tmp=tmp->next;
         }

        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val!=s.top())return false;
            else{
                curr=curr->next;
                s.pop();
            }
        }
        return true;
        
    }
};
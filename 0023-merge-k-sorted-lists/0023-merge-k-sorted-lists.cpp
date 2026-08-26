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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto &x:lists){
            while(x!=nullptr){
                pq.push({x->val,x});
                x=x->next;
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top().second;
            temp->next=node;
            temp=temp->next;
            pq.pop();
        }
        return dummy->next;
    }
};
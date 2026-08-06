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
        priority_queue<pair<int,ListNode*>,
                        vector<pair<int,ListNode*>>,
                        greater<pair<int,ListNode*>>>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
                pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(!pq.empty()){
            int data=pq.top().first;
            ListNode* node=pq.top().second;
            if(node->next!=NULL){
                pq.push({node->next->val,node->next});
            }
            pq.pop();
            temp->next=new ListNode(data);
            temp=temp->next;
        }

        return dummy->next;
    }
};
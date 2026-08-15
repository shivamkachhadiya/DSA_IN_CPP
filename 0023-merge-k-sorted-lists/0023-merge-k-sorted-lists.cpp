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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        if (lists.size() == 0)
            return nullptr;

        for (auto node : lists) {
            while (node != nullptr) {
                pq.push({node->val, node});
                node = node->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        ListNode* temp = dummy;
        while (!pq.empty()) {
            int val = pq.top().first;
            ListNode* node = pq.top().second;

            temp->next = node;
            temp = temp->next;
            pq.pop();
        }
        return dummy->next;
    }
};
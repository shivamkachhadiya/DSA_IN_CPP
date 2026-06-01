class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min-heap comparator
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // sabhi list ke head push karo
        for (auto node : lists) {
            if (node) pq.push(node);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node; // sabse chhota node add karo
            tail = tail->next;
            if (node->next) pq.push(node->next); // agla node push karo
        }
        
        return dummy.next;
    }
};

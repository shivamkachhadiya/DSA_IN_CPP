class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        
        // dummy node banate hain easy insertion ke liye
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head->next;
        head->next = nullptr;
        
        // har node ko sahi jagah insert karna hai
        while (curr) {
            ListNode* nextNode = curr->next; // agla node store karo
            ListNode* prev = dummy;
            ListNode* temp = dummy->next;
            
            // sahi position dhundho
            while (temp && temp->val < curr->val) {
                prev = temp;
                temp = temp->next;
            }
            
            // insert karo
            curr->next = temp;
            prev->next = curr;
            
            // agle node par jao
            curr = nextNode;
        }
        
        return dummy->next;
    }
};

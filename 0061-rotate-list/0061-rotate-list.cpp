class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
      
        ListNode* current = head;
        int length = 0;
        while (current) {
            ++length;
            current = current->next;
        }
      
        k %= length;
      
        if (k == 0) {
            return head;
        }
      
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
      
        while (k--) {
            fastPointer = fastPointer->next;
        }
        while (fastPointer->next) {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }
      
        ListNode* newHead = slowPointer->next;
      
        slowPointer->next = nullptr;
      
        fastPointer->next = head;
      
        return newHead;
    }
};

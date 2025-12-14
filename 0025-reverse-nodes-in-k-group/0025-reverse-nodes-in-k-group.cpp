class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == nullptr) return nullptr;

        // Step 1: check k nodes exist
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (curr == nullptr) return head; // ❗IMPORTANT
            curr = curr->next;
        }

        // Step 2: reverse k nodes
        curr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: recursion
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;

        // Traverse the list in pairs
        while (curr != nullptr && curr->next != nullptr) {
            // Swap values
            swap(curr->val, curr->next->val);

            // Move to the next pair
            curr = curr->next->next;
        }

        return head;
    }
};

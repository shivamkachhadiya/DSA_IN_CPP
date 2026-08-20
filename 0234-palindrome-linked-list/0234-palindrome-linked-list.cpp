class Solution {
public:
    ListNode* curr;
    bool recur(ListNode* head) {
        if (head == nullptr)
            return true;

        bool ans = recur(head->next);

        if (head->val != curr->val) {
            return false;
        }
        curr = curr->next;

        return ans;
    }
    bool isPalindrome(ListNode* head) {
        curr=head;
        return recur(head);
    }
};
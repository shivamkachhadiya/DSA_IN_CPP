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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        auto tmp = head;
        while (tmp != nullptr) {
            count++;
            tmp = tmp->next;
        }
        if (n == count) {
            return head->next;
        }
        // now count=5
        int target = count - n; // 3
        int track = 1;
        tmp = head;
        while (track != target) {
            track++;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return head;
    }
};
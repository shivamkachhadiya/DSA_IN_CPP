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
    int NodeCount(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = NodeCount(head);
        if (n == count) {
            ListNode* newHead = head->next;
            delete head; // Optional: free memory
            return newHead;
        }

        int target = count - n-1;
        ListNode* temp = head;
        for (int i = 0; i < target; i++) {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};
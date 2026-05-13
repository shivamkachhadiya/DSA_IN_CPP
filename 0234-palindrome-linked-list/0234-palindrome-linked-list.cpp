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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->next;
        }
        ListNode* t1 = head;
        while (!st.empty()) {
            ListNode* front = st.top();
            if (front->val != t1->val) {
                return false;
            }
            st.pop();
            t1 = t1->next;
        }
        return true;
        
    }
};
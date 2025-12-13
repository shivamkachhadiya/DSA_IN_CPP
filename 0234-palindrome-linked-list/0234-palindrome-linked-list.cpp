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
        ListNode* temp = head;
        vector<int> arr;
        while (temp != nullptr) {
            arr.push_back(temp->val);

            temp = temp->next;
        }
        int n = arr.size();
        int start = 0, end = n - 1;
        while (start <= end) {
            if (arr[start] != arr[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
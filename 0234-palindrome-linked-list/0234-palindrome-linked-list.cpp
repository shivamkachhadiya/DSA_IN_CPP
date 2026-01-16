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
    void solve(ListNode* head, vector<int>& arr) {

        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        solve(head, arr);
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
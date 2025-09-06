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
    int gcd(int a, int b) {
        if (b == 0)
            return a;         // base case
        return gcd(b, a % b); // recursive call
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tempVar1 = head;
        ListNode* tempVar2 = tempVar1->next;

        while (tempVar1 != NULL && tempVar2 != NULL) {
            int gcd_ans = gcd(tempVar1->val, tempVar2->val);

            // naya gcd node banao
            ListNode* newNode = new ListNode(gcd_ans);

            // usko tempVar1 aur tempVar2 ke beech mein lagao
            tempVar1->next = newNode;
            newNode->next = tempVar2;

            // aage move karo
            tempVar1 = tempVar2;
            tempVar2 = tempVar1->next;
        }
        return head;
    }
};

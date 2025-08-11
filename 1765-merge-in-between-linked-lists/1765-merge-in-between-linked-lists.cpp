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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1=list1;
        ListNode* curr2=list2;

        int count = 0;
        while (count < a - 1) {
            curr1 = curr1->next;
            count++;
        }

        ListNode* beforeA = curr1;

         while (count < b) {
            curr1 = curr1->next;
            count++;
        }


        ListNode* nextptr = curr1->next;

         beforeA->next = curr2;

         while (curr2->next != NULL) {
            curr2 = curr2->next;
        }

         curr2->next = nextptr;
         return list1; 
        
    }
};
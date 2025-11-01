// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         ListNode* temp1 = head;

//         int n = nums.size();
//         int i = 0;
//         while (temp1 != NULL && temp1->next != NULL) {
            
//             // while (i < n) {
//             //     if (nums[i] != temp1->val) {
//             //         temp1->next = temp1->next->next;
//             //         temp1 = temp1->next;
//             //     } else {
//             //         temp1 = temp1->next;
//             //         head = head->next;
//             //     }
//             //     i++;
//             // }

//             // temp1=temp1->next;

//             while(i<n){
//                 if(nums[i]==temp1->val){
//                     temp1=temp1->next;

//                 }

//                 i++;
//                 if(i==n){
//                     head=temp1;
//                     temp1=temp1->next;
//                     i=0;
//                 }
//             }


//         }
//         return head;
//     }
// };


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step 1: Store nums in a hash set for fast lookup
        unordered_set<int> toRemove(nums.begin(), nums.end());
        
        // Step 2: Remove all nodes from the beginning if they need to be deleted
        while (head && toRemove.count(head->val)) {
            head = head->next;
        }

        // Step 3: Now traverse and remove from the middle
        ListNode* curr = head;
        while (curr && curr->next) {
            if (toRemove.count(curr->next->val)) {
                curr->next = curr->next->next; // skip this node
            } else {
                curr = curr->next; // move forward
            }
        }

        return head;
    }
};

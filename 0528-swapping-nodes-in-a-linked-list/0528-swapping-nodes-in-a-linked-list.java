/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
        static int countall(ListNode head) {
        int count = 0;
        ListNode temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        return count;
    }
    public ListNode swapNodes(ListNode head, int k) {

                ListNode start = head;
        int count = 1;
        while (count != k) {
            count++;
            start = start.next;
        }
        // now start pointing starting k

        ListNode end = head;
        int countall = countall(head);
        int target = (countall - k) + 1;
        int currcount = 1;
        while (currcount != target) {
            currcount++;
            end = end.next;
        }

        // now end pointing last kth index

        int startval = start.val;
        int endval = end.val;
        start.val = endval;
        end.val = startval;

        return head;
        
    }
}

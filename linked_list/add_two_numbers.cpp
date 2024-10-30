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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;

        int carry = 0;
        while(l1 || l2 || carry) {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;
            int sum = carry + val1 + val2;

            ListNode *node_nw = new ListNode(sum % 10);
            cur->next = node_nw;
            cur = cur->next;

            carry = sum / 10;

            if(l1)
               l1 = l1->next;

            if(l2)
               l2 = l2->next;
        }

        return dummy.next;
    }
};

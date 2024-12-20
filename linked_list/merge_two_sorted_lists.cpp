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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;

        while(list1 && list2) {
            if(list1->val > list2->val) 
                swap(list1, list2);

            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }

        if(list1) {
            cur->next = list1;
        }
        else if(list2) {
            cur->next = list2;
        }

        return dummy.next;
    }
};

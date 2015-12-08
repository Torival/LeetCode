/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* list1 = NULL, *list2 = NULL;
        ListNode** l1 = &list1, **l2 = &list2;
        while(head) {
            if(head->val < x) {
                *l1 = head;
                l1 = &(*l1)->next;
            } else {
                *l2 = head;
                l2 = &(*l2)->next;
            }
            head = head->next;
        }
        *l1 = list2;
        *l2 = NULL;
        return list1;
    }
};


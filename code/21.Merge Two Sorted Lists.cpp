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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* pre, *p2 = l2;
        pre = new ListNode(0);
        pre->next = p2;
        l2 = pre;
        while(l1) {
            while(p2 && p2->val < l1->val) {
                pre = p2;
                p2 = p2->next;
            }
            if(!p2 || p2->val >= l1->val) {
                pre->next = l1;
                l1 = l1->next;
                pre->next->next = p2;
                pre = pre->next;
            }
        }
        return l2->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** ptail = &head;
        while(l1 && l2) {
            if(l1->val < l2->val){
                *ptail = l1;
                l1 = l1->next;
            } else {
                *ptail = l2;
                l2 = l2->next;
            }
            ptail = &((*ptail)->next);
        }
        *ptail = (l1 != NULL ? l1 : l2);
        return head;
    }
};

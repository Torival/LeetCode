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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head, *s = p->next, *t = s->next;

        p->next = NULL;
        while(t) {
            s->next = p;
            p = s;
            s = t;
            t = t->next;
        }
        s->next = p;
        return s;
    }
};

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==n) return head;
        ListNode* p = head ,*s;
        n -= m;
        while(m) {
            s = p, m--;
            p = p->next;
        }
        if(!p || !p->next) return head;
        ListNode *t1 = p, *t2 = t1->next, *t3 = t2->next;
    
        while(n) {
            t2->next = t1;
            t1 = t2, t2 = t3, n--;
            t3 = t3->next;
        }
        s->next->next = t3;
        s->next = t2;
        return head;       
    }
};

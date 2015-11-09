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
        ListNode* p = head ,*s = head;
        n -= m;
        while(m-1) {
            s = p, m--;
            p = p->next;
        }
        ListNode *t1 = p, *t2 = t1->next, *t3 = t2->next;	
		while(n) {
            t2->next = t1;
            t1 = t2, t2 = t3, n--;
            if(t3) t3 = t3->next;
        }
        if(p == head){ 
            s->next = t2;
            return t1;
        }
        s->next->next = t2;
        s->next = t1;
        return head;   
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head || !head->next) return head;
    struct ListNode *p = head, *t = p->next, *s = p;
    int flag = 0;
    while(t) {
    	if(p->val == t->val) {
    		p->next = t->next;
    		t = p->next;
    		flag = 1;
    		continue;
		}
		if(flag) {
			p->val = t->val;
			p->next = t->next;
			t = p->next;
    		flag = 0;
    		continue;
		}
		s = p;
		p = p->next;
		t = p->next; 
	}
	if(flag==1 && head->next) s->next = NULL;
	else if(flag == 1) head = NULL;
	return head;
}

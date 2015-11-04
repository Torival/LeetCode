/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if(!l1) return l2;
	if(!l2) return l1;
	ListNode *p, *top=l1, *k;
	int temp = 0;
	while(top || l2) {
		k = top;
		if(l2) {
			temp += l2->val, l2 = l2->next;
		}
		if(top) {
			temp += top->val, top->val = temp%10;
			temp =temp / 10, top = top->next;
		}
		if(l2 && (!top)){
			p = new ListNode(0);
			k->next = p;
			top = p;
		}
		if((!top)&&(!l2)&&temp) {
			p = new ListNode(temp);
			k->next = p;
		}
	}
    	return l1;
}

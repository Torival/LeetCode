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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p, *s;
        int temp;
        p = head;
        s = p->next;
        while(s) {
		temp = p->val;
		p->val = s->val;
		s->val = temp;
		s = s->next;
		if(s) {
			s = s->next;
			p = p->next->next;
		}
	}	
	return head;
    }
};

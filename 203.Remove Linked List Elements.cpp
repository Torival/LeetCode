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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        if(head->val==val && !head->next) return NULL;
        
        ListNode* p = head;
        ListNode* t = head->next;
        while(t!=NULL) {
			if(t->val == val) {
				p->next = t->next;
				delete t;
				t = p->next;
				continue;
			}
			p = p->next;
			t = t->next;
		}
		if(head->val == val && head->next) {
			t = head->next;
			head->val = head->next->val;
			head->next = head->next->next;
			delete t;
		}
		if(head->val == val && !head->next) {
			delete head;
			head = NULL;
		}
		return head;
    }
};

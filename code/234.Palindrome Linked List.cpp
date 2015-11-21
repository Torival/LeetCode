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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        if(!head->next->next && head->val==head->next->val) return true;
        if(!head->next->next && head->val!=head->next->val) return false;
        ListNode *fast = head, *slow = head;
        ListNode *p = head,*s = p->next, *t = s->next;
        int len = 0;
        //龟兔赛跑算法，一快一慢找到中间值 
        while(fast) {
            fast = fast->next;
            slow = slow->next;
            len++;
            if(fast) {
                len++;
                fast = fast->next;
            }
        }
        //链表逆置 
        while(t!=slow && t) {
            s->next = p;
            p = s, s = t;
            t = t->next;
        }
        s->next = p;
        head->next = slow;
        if(len % 2) s = s->next;
        len = len / 2; 
        while(len--) {
            if(s->val != slow->val) return false;
            s = s->next, slow = slow->next;
        }
        return true;
    }
};

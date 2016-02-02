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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* psort = new ListNode(0);
        ListNode *ptail = head, *pre;
        
        psort->next = head;
        head = head->next, ptail->next = NULL;
        while(head) {
            pre = psort;
            ptail = pre->next;
            while(ptail && ptail->val < head->val) {
                pre = pre->next;
                ptail = ptail->next;
            }
            pre->next = head;
            head = head->next;
            pre->next->next = ptail;
        }
        return psort->next;
    }
};


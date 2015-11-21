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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptail = head;
        int len = 0;
        
        while(ptail) {
            ptail = ptail->next;
            len++;
        }
        
        if(len < n) return head;
        if(len == n) return head->next;
        
        ptail = head;
        for(int i=0; i<len-n-1; i++) {
            ptail = ptail->next;
        }
        ptail->next = ptail->next->next;
        return head;
    }
};

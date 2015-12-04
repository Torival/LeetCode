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
    ListNode* sortList(ListNode* head) {
        if(head && head->next) {
            ListNode* mid = getmid(head), *start = mid->next;
            mid->next = NULL;
            head = sortList(head);
            start = sortList(start);
            return merge(head, start);
        } else return head;
    }
    
    ListNode* merge(ListNode* head, ListNode* start) {
        ListNode* ptail = NULL;
        ListNode** psort = &ptail;
        while(head && start) {
            if(start->val > head->val) {
                *psort = head;
                head = head->next;
            } else {
                *psort = start;
                start = start->next;
            }
            psort = &(*psort)->next;
        }
        start == NULL ? *psort = head : *psort = start;
        return ptail;
    }
    
    ListNode* getmid(ListNode* head) {
        int num = -1;
        ListNode* ptail = head;
        while(ptail){
            num++;
            ptail = ptail->next;
        } 
        num /= 2;
        while(num--) head = head->next;
        return head;
    }
};

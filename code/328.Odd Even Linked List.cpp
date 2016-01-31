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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* l1 = head;
        ListNode* l2 = l1->next, *temp = l1->next;
        
        while(l1 && l1->next && l2 && l2->next) {
            l1->next = l2->next;
            l1 = l1->next;
            l2->next = l1->next;
            l2 = l2->next;
        }
        l1->next = temp;
        
        return head;
    }
};

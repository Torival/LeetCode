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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode* ptail = head;
        while(head) {
            head = head->next;
            ptail = ptail->next;
            if(head) head = head->next;
            if(ptail == head) break;
        }
        
        if(head) return true;
        else return false;
    }
};

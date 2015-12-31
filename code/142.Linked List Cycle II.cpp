/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *假设环为a-b-c-b;由于fast的速度是slow的两倍，
 *所以fast走的距离是slow的两倍，有 2(ab+bc) = ab+bc+cb+bc -> ab = cb
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ptail = head;
        while(head) {
            head = head->next;
            ptail = ptail->next;
            
            if(head) head = head->next;
            if(ptail == head) break;
        }
        
        if(head) return true;
        else return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head)) return NULL;
        
        while(head != ptail) {
            head = head->next;
            ptail = ptail->next;
        }
        return head;
     }
private:
    ListNode* ptail;
};

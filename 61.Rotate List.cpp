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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* pre = head, *ptail = head;
        int count = 0;

        while(ptail->next) {
            ptail = ptail->next;
            count++;
        }
        ptail->next = head;
        k = count - k % (count+1);
        while(k-- > 0) {
            pre = pre->next;
        }
        ptail = pre->next;
        pre->next = NULL;
        return ptail;
    }
};


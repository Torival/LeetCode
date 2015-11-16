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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        if(!headA || !headB) return NULL;
        int lena = getLength(headA);
        int lenb = getLength(headB);

        if(lena < lenb) { 
            swap(headA, headB);
            swap(lena, lenb);
        }
        for(int i=0; i<(lena-lenb); i++) headA = headA->next;
        while(headA) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    int getLength(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
}

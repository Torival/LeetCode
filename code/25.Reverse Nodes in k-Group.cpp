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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k <= 1) return head;
        int num = getNum(head, k);
        if(num == 0) return head;
        
        ListNode* p = reverse(head, k, num);
        ListNode* ptail = head, *pre = head->next, *temp;
        while((temp = reverse(pre, k, num)) != pre) {
            ptail->next = temp;
            ptail = pre;
            pre = pre->next;
        }
        return p;
    }
    
    int getNum(ListNode* head, int k) {
        int num = 0;
        while(head) {
            num++;
            head = head->next;
        }
        return num /= k;
    }

    ListNode* reverse(ListNode* head, int k, int &num) {
        if(!num--) return head;
        ListNode *post = head, *pre = head->next->next, *mid = head->next;
        while(pre && (k-- - 2)) {
            mid->next = post;
            post = mid, mid = pre;
            pre = pre->next;
        }
        head->next =mid->next;
        mid->next = post;
        return mid;
    }
};



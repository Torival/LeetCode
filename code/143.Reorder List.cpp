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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;

        ListNode* mid = getMid(head);
        ListNode* p = reverse(mid->next);

        mid->next = NULL;
        ListNode* pre = head, *temp;
        //合并俩条链表
        while(pre) {
            temp = p->next;
            p->next = pre->next;
            pre->next = p;
            pre = pre->next->next;
            p = temp;
            if(!p) break;
        }
    }
    
    //快慢指针获取中间节点
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //翻转后半部分链表
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *post = head, *pre = head->next->next, *mid = head->next;
        head->next = NULL;
        while(pre) {
            mid->next = post;
            post = mid, mid = pre;
            pre = pre->next;
        }
        mid->next = post;
        return mid;
    }
};


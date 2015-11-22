/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //分而治之，递推解决
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num = lists.size();
        if(!num) return NULL;
        return mergeKLists(lists, 0, num-1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int low, int high) {
        if(high > low) {
            return mergeTwoLists(mergeKLists(lists, low, (low+high)/2), mergeKLists(lists, (low+high)/2+1, high));
        }else {
            return lists[low];
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** ptail = &head;
        while(l1 && l2) {
            if(l1->val < l2->val){
                *ptail = l1;
                l1 = l1->next;
            } else {
                *ptail = l2;
                l2 = l2->next;
            }
            ptail = &((*ptail)->next);
        }
        *ptail = (l1 != NULL ? l1 : l2);
        return head;
    }
};

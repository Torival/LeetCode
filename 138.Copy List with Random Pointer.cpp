/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 //算法一、通过hashtable建立原链表与新链表的映射关系 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        map<RandomListNode*, RandomListNode *> map;
        RandomListNode* phead = new RandomListNode(head->label);
        phead->random = head->random;
        map[head] = phead;
        RandomListNode* p = head->next;
        RandomListNode* pnew = phead, *ptail = phead; 
        
        while(p) {
            pnew = new RandomListNode(p->label);
            ptail->next = pnew;
            pnew->random = p->random;
            map[p] = pnew;
            p = p->next;
            ptail = ptail->next;
        }
        ptail = phead;
        while(ptail) {
            if(ptail->random)
                ptail->random = map[ptail->random];
            ptail = ptail->next;
        }
        return phead;
    }
};

/*
 *算法二、该算法是通过三次遍历链表来实现深拷贝
 * 1.在每一个结点后面插入一个与其相同的结点，使其random，next指针域相同
 * 2.遍历新链表，如果random不为空的话，就让random指向random->next 
 * 3.重新整合为一条新链表 
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode* ptail =head, *pnew; 
        
        while(ptail) {
            pnew = new RandomListNode(ptail->label);
            pnew->next = ptail->next;
            pnew->random = ptail->random;
            ptail->next = pnew;
            ptail = ptail->next->next;
        }
        ptail = head->next;
        while(ptail) {
            if(ptail->random)
                ptail->random = ptail->random->next;
            ptail = ptail->next;
            if(ptail) ptail = ptail->next;
        }
        
        ptail = head->next;
        pnew = head->next;
        while(ptail) {
            head->next = ptail->next;
            if(ptail->next) ptail->next = ptail->next->next;
            ptail = ptail->next;
            head = head->next;
        }
        return pnew;
    }
};
 

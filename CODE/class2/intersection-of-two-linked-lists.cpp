/*  
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
解法见：https://labuladong.gitee.io/algo/2/17/16/
让 p1 遍历完链表 A 之后开始遍历链表 B，让 p2 遍历完链表 B 之后开始遍历链表 A，
这样相当于「逻辑上」两条链表接在了一起。
如果这样进行拼接，就可以让 p1 和 p2 同时进入公共部分，也就是同时到达相交节点 c1
*/
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
        if(!headA || !headB)
            return NULL;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            // p1 走一步，如果走到 A 链表末尾，转到 B 链表
            if (p1 == NULL) 
                p1 = headB;
            else
                p1 = p1->next;
            // p2 走一步，如果走到 B 链表末尾，转到 A 链表
            if (p2 == NULL) 
                p2 = headA;
            else            
                p2 = p2->next;
        }
        return p1;
    }
};








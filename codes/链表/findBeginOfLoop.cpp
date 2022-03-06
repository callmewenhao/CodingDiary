/* 
https://leetcode-cn.com/problems/c32eOV/  or https://leetcode-cn.com/problems/linked-list-cycle-ii/
Given a circular linked list, return the node at the beginning of the loop
解题分析:寻找某个特定位置，
用runner technique。Runner以两倍速度遍历，
假定有loop，那么runner与chaser一定能在某点相遇。
相遇后，再让chaser从head出发再次追赶runner，第二次相遇的节点为loop开始的位置。
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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;

        ListNode *runner = head;
        ListNode *chaser = head;
        while(runner && runner->next){
            runner = runner->next->next;
            chaser = chaser->next;
            if(runner == chaser)
                break;
        }
        if(runner != chaser){  // 没有环
            return NULL;
        }
        chaser = head;
        while(runner != chaser){
            runner = runner->next;
            chaser = chaser->next;
        }
        return chaser;
    }
};
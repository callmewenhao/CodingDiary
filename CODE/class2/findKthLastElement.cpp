/*  
https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
Find the kth to last element of a singly linked list
解题分析:与寻找中间node类似。只是runner与chaser以相同倍速前进，但runner提前k步出发
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == NULL || k < 0)
            return NULL;
        
        ListNode *runner = head;
        ListNode *chaser = head;
        while(runner->next && k > 1){  // 指针1先走k-1步
            runner = runner->next;
            k--;
        }
        while(runner->next){  // 指针2和指针1同时前进
            runner = runner->next;
            chaser = chaser->next;
        }
        return chaser;
    }
};















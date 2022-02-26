/*  
https://leetcode-cn.com/problems/rotate-list/
解题思路：快慢指针
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;

        ListNode* runner = head;
        ListNode* chaser = head;
        for(int i = 0; i < k;){
            if(!runner->next) {
                // 处理 k 大于链表长度的情况
                k = k % (i+1);
                i = 0;
                runner = head;
            }
            else {
                runner = runner->next;
                i++;
            }
        }
        while(runner->next){
            runner = runner->next;
            chaser = chaser->next;
        }
        runner->next = head;
        head = chaser->next;
        chaser->next = nullptr;
        return head;
    }
};
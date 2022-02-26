/*  
https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/
Swap Adjacent Nodes 交换相邻结点
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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return nullptr;

        ListNode *dummy = new ListNode(0, head);
        ListNode *runner = dummy, *chaser = dummy;
        ListNode *k1 = nullptr, *k2 = nullptr;
        for(int i = 1; i < k; i++){
            runner = runner->next;
        }
        k1 = runner;
        while(runner->next->next){
            runner = runner->next;
            chaser = chaser->next;
        }
        k2 = chaser;
        // swap
        // swap pre
        ListNode *temp = k1->next;
        k1->next = k2->next;
        k2->next = temp;
        k1 = k1->next;
        k2 = k2->next;
        // swap next
        temp = k1->next;
        k1->next = k2->next;
        k2->next = temp;
        return dummy->next;
    }
};
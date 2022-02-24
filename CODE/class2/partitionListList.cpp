/*  
https://leetcode-cn.com/problems/partition-list/
Given a linked list and a value x, 
write a function to reorder this list
such that all nodes less than x come before the nodes greater than or equal to x.
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
/* 
构造出两个子链表，最后合并 
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return nullptr;
        }

        ListNode *leftDummy = new ListNode(0);
        ListNode *left = leftDummy;
        ListNode *rightDummy = new ListNode(0);
        ListNode *right = rightDummy;
        ListNode *node = head;
        while(node != nullptr){
            if(node->val < x){
                left->next = node;
                left = left->next;
            } else {
                right->next = node;
                right = right->next;
            }
            node = node->next;
        }
        right->next = nullptr;
        left->next = rightDummy->next;
        return leftDummy->next;
    }
};
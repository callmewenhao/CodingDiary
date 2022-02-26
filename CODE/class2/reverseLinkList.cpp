/*  
Reverse Linked List
Reverse the linked list and return the new head.
循环遍历linked-list,每次只处理当前指针的next变量。
非递归vs递归
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
    // 非递归：遍历一遍链表
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* tail = nullptr;
        while(head){
            ListNode* curr = head;
            head = head->next;
            curr->next = tail;
            tail = curr;
        }
        return tail;
    }
    // 递归
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};













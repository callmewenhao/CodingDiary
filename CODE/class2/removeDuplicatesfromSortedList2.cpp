// leetcode: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(0, head);  // new 返回指针
        ListNode* node = dummy;
        while(node->next != nullptr && node->next->next != nullptr){
            if(node->next->val == node->next->next->val){
                int val = node->next->val;
                // 接下来把这个值的结点全部删掉
                while(node->next != nullptr && node->next->val == val){
                    node->next = node->next->next;
                } 
            } else
                node = node->next;
        }
        return dummy->next;
    }
};





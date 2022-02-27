/* 
Add List Sum
https://leetcode-cn.com/problems/sum-lists-lcci/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
从前向后计算，生成新node存储
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }
        return head->next;
    }
};









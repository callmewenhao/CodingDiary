/* 
https://leetcode-cn.com/problems/swap-nodes-in-pairs/
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *node0 = dummy;
        while(node0->next != NULL && node0->next->next != NULL){
            ListNode *node1 = node0->next;
            ListNode *node2 = node0->next->next;
            // swap
            node0->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            // update
            node0 = node1;
        }
        return dummy->next;
    }
};
/*  
Find the middle point of linked list.
解题分析:寻找特定位置，runner以两倍速前进，chaser一倍速，当runner到达tail时,chaser即为所求解。
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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode *runner = head, *chaser = head;
        while(runner && runner->next){  // 应对偶数情况
            chaser = chaser->next;
            runner = runner->next->next;
        }
        return chaser;
    }
};










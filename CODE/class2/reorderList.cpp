/*  
Reorder List
https://leetcode-cn.com/problems/reorder-list/
解题思路：
使用vector数组存储对应位置的指针
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        ListNode *temp = head;
        vector<ListNode*> myList;
        while(temp != nullptr){
            myList.push_back(temp);
            temp = temp->next;
        }
        int l = myList.size();
        int left = 0;
        int right = l - 1;
        for(; left < right; left++, right--){
            myList[left]->next = myList[right];
            myList[right]->next = myList[left + 1];
        }
        myList[left]->next = nullptr;
        return;
    }
};




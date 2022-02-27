/* 
回文链表 
https://leetcode-cn.com/problems/palindrome-linked-list/
思路一：使用一个线性表存贮val或者指针，然后使用前后指针，这样的话空间复杂度大
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
    bool isPalindrome(ListNode* head) {
        vector<int> myList;
        ListNode* temp = head;
        while(temp != nullptr){
            myList.push_back(temp->val);
            temp = temp->next;
        }
        int l = myList.size();
        int left = 0;
        int right = l-1;
        for(;left <= right; left++, right--){
            if(myList[left] != myList[right]){
                return false;
            }
        }
        return true;
    }
};



/*  
Merge K Sorted List
https://leetcode-cn.com/problems/merge-k-sorted-lists/
HEAP
1.Create a heap to store ListNode*, 
which should sort list nodes in theascending order or node values.
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
class mycomparison {
public:
    bool operator() (ListNode* &a, ListNode* &b) const {
        return a->val > b->val;  // 从小到达排列
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycomparison> pq;  // 优先队列
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        // 向优先队列里push元素
        for(ListNode* node : lists){
            if(node != nullptr)
                pq.push(node);
        }
        cout<<123;
        while(!pq.empty()){
            ListNode *top = pq.top();
            pq.pop(); // 不要忘记取出来！
            temp->next = top;
            if(top->next != nullptr)
                pq.push(top->next);
            temp = temp->next;
        }
        return dummy->next;
    }
};



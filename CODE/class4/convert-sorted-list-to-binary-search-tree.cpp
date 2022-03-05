/*
https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
*/
// 解法一：借助之前数组转BST方法，利用快慢指针找中点+递归，注意左闭右开区间的使用
class Solution {
private:
    ListNode* getMidNode(ListNode* begin, ListNode* end) {
        ListNode* faster = begin;
        ListNode* slower = begin;
        while(faster != end && faster->next != end) {
            faster = faster->next->next;
            slower = slower->next;
        }
        return slower;
    }

    TreeNode* buildBST(ListNode* begin, ListNode* end) {
        // recurse stop condition
        // 在这个(begin, end)左闭右开的区间内寻找！
        if(begin == end) return nullptr;// 代表区间内已经没有元素
        // if(mid == nullptr) return nullptr;
        // find middle node
        ListNode* mid = getMidNode(begin, end);
        // build BST
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildBST(begin, mid);
        root->right = buildBST(mid->next, end);  // 注意这里的起止位置
        return root;
    }
public:
    // 分治+快慢指针找中点
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        return buildBST(head, nullptr);
    }
};


// 解法二：借助中序遍历！
class Solution {
private:
    ListNode* cur; // 在递归的过程中会维护这个指针

    TreeNode* inorderBuild(int left, int right) {
        if(left > right) return nullptr;

        int mid = (left + right) / 2;
        // 构造左子树
        TreeNode* leftTree = inorderBuild(left, mid - 1);
        // 构造根节点
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next; // 重新开始
        // 构造右子树
        TreeNode* rightTree = inorderBuild(mid + 1, right);
        // 将左右子树接到根节点上
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        int len = 0;
        for(ListNode* node = head; node != nullptr; node = node->next) {
            len++;
        }
        cur = head;
        return inorderBuild(0, len - 1);
    }
};


















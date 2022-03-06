/*
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;  // 异常处理
        /*
		递归停止的条件应该是：p < root && root < q，即root位于pq之间！
        */
        TreeNode* ancestor = root;
        if(p->val < root->val && q->val < root->val)  // 全在左边
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val) // 全在右边
            return lowestCommonAncestor(root->right, p, q);
        return ancestor; // 在中间，包括相等
    }
};
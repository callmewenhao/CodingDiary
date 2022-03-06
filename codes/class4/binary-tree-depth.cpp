/*
https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
树的深度 == 树的最大深度
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
	// 递归解法
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ld = maxDepth(root->left) + 1;
        int rd = maxDepth(root->right) + 1;
        return ld > rd ? ld : rd;
    }
};













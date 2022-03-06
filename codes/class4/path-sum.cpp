/*https://leetcode-cn.com/problems/path-sum/*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 使用递归解法
    /* 递归时传入新的根节点和新的sum */
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        if(root->left == root->right && root->val == targetSum)
            return true;
        return hasPathSum(root->left, targetSum - root->val) || \
               hasPathSum(root->right, targetSum - root->val);
    }
};
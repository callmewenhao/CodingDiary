https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
/* 
判断是否为平衡二叉树：左右子树满足平衡二叉树定义，并且左右子树高度差<=1
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
private:
    int nodeLen(TreeNode* node) {
        if(node == nullptr) return 0;
        else {
            int ll = nodeLen(node->left);
            int lr = nodeLen(node->right);
            int m = ll > lr ? ll : lr;
            return m + 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) 
            return true;
        int d = abs(nodeLen(root->left) - nodeLen(root->right));
        return (d <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
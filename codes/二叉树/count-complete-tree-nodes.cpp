// https://leetcode-cn.com/problems/count-complete-tree-nodes/
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
    // 通过递归计算树高
    // 递归截止的条件是：完全左右子树高度一致（满二叉树），不一致就继续进行递归
    int countNodes(TreeNode* root) {
        TreeNode* l = root;
        TreeNode* r = root;
        // 截止条件
        int lh = 0, rh = 0;
        while(l != nullptr) {
            l = l->left;
            lh++;
        }
        while(r != nullptr) {
            r = r->right;
            rh++;
        }
        if(lh == rh) {
            return (int) (pow(2, lh) - 1);
        }
        // 继续递归
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};





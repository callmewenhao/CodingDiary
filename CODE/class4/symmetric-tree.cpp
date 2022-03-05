/*
https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
    bool isSame(TreeNode* left, TreeNode* right) {
    	/*判断对称位置是否相等*/
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr|| right == nullptr) return false;

        if(left->val == right->val)
            return isSame(left->left, right->right) && isSame(left->right, right->left);
        else return false;
    }
public:
    // 使用递归方法
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSame(root->left, root->right);
    }
};





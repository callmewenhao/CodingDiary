/*
https://leetcode-cn.com/problems/check-subtree-lcci/
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
    // 递归方法
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false; // 同时为空已经被上句代码排除

        if(t1->val == t2->val) { 
            // 根结点相同
            return checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
        } else {
            // 根结点不相同
            return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
        }
    }
};
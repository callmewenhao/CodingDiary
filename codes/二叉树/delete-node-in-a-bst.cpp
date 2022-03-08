// https://leetcode-cn.com/problems/delete-node-in-a-bst/
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
private:
    int getMinNode(TreeNode* root) {
        // 找BST中的最小结点
        if(root == nullptr) return -1;
        if(root->left == nullptr) return root->val;
        return getMinNode(root->left);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 递归停止条件
        if(root == nullptr) return nullptr;
        // 找到待删结点
        if(root->val == key) {
            // 第一种情况：其左子树为空，右子树代替他
            if(root->left == nullptr) return root->right;
            // 第二种情况：其右子树为空，左子树代替他，
            // 同时，这两种情况也解决了左右子树同时为空的情况
            else if(root->right == nullptr) return root->left;
            else {// 左右子树都不为空的情况
                // 先找右子树中的最小结点（或左子树最大结点），然后替换到root
                int rightMin = getMinNode(root->right);
                root->val = rightMin;
                // 删除这个最小结点
                root->right = deleteNode(root->right, rightMin);
            }
        }
        // 待删结点在右子树中，更新右子树
        if(root->val < key) 
            root->right = deleteNode(root->right, key);
        // 待删结点在左子树中，更新左子树
        if(root->val > key)
            root->left = deleteNode(root->left, key);

        return root;
    }
};





/*
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/*
/
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
    // 使用递归的解法
    void flatten(TreeNode* root) {
        if(root == nullptr) return; // 空结点返回
        // flatten 左右子树
        flatten(root->left);
        flatten(root->right);
        // 拼接操作
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        // 寻找拼接的位置
        TreeNode* node = root;
        while(node->right != nullptr) {
            node = node->right;
        }
        node->right = right;
    }
};

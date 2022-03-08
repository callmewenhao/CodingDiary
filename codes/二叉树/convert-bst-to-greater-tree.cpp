// https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
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
    // 使用反序中序遍历
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;

        stack<TreeNode*> nodeStack;
        TreeNode* node = root;
        int sum = 0;

        while(!nodeStack.empty() || node != nullptr) {
            while(node != nullptr) {
                nodeStack.push(node);
                node = node->right;
            }
            node = nodeStack.top();
            nodeStack.pop();
            node->val += sum;
            sum = node->val;
            node = node->left;
        }
        return root;
    }
};












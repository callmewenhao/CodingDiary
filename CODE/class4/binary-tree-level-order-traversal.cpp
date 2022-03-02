/* https://leetcode-cn.com/problems/binary-tree-level-order-traversal/ */
/* 二叉树层序遍历 */
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> nodeQueue1, nodeQueue2;
        /* 我的想法是使用两个队列存储相邻level的nodes */

        nodeQueue1.push(root);
        while(!nodeQueue1.empty() || !nodeQueue2.empty()) {
            vector<int> resultPlane;
            if(!nodeQueue1.empty()) {
                while(!nodeQueue1.empty()) {
                    TreeNode* node = nodeQueue1.front();
                    nodeQueue1.pop();
                    resultPlane.push_back(node->val);
                    if(node->left != nullptr) nodeQueue2.push(node->left);
                    if(node->right != nullptr) nodeQueue2.push(node->right);
                }
            } else {  // !nodeQueue2.empty()
                while(!nodeQueue2.empty()) {
                    TreeNode* node = nodeQueue2.front();
                    nodeQueue2.pop();
                    resultPlane.push_back(node->val);
                    if(node->left != nullptr) nodeQueue1.push(node->left);
                    if(node->right != nullptr) nodeQueue1.push(node->right);
                }
            }
            result.push_back(resultPlane);
        }
        return result;
    }
};














/* 
https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
二叉树层序遍历2 官方解法+反序！：
*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            result.push_back(vector<int>());
            int nodeNums = nodeQueue.size();
            for(int i = 0; i < nodeNums; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                result.back().push_back(node->val);
                if(node->left != nullptr) nodeQueue.push(node->left);
                if(node->right != nullptr) nodeQueue.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }   
};


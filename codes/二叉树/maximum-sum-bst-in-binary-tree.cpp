// https://leetcode-cn.com/problems/maximum-sum-bst-in-binary-tree/
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
    int maxSum = 0;
    vector<int> traverse(TreeNode* root) {
        if(root == nullptr) {
            return vector<int> {1, INT_MAX, INT_MIN, 0};
        }
        // 判断左子树
        vector<int> leftTree = traverse(root->left);
        // 判断右子树
        vector<int> rightTree = traverse(root->right);
        // 当前树
        vector<int> res(4, 0);
        if(leftTree[0] == 1 && rightTree[0] == 1 && \
            root->val > leftTree[2] && root->val < rightTree[1]) {
            // BST
            res[0] = 1;
            // 最小值
            res[1] = min(leftTree[1], root->val);
            // 最大值
            res[2] = max(root->val, rightTree[2]);
            // 和
            res[3] = leftTree[3] + rightTree[3] + root->val;
            // 更新和
            maxSum = max(maxSum, res[3]);
        } else {
            res[0] = 0;
        }
        return res;
    }

public:
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxSum;
    }
};



// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
    // 中序遍历！
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return -1;

        int count = 0;
        int res = 0;
        stack<TreeNode*> nodeStack;
        while(!nodeStack.empty() || root != nullptr) {
            // 深搜左子树
            while(root != nullptr) {
                nodeStack.push(root);
                root = root->left;
            }
            // 返回最左端结点
            root = nodeStack.top();
            nodeStack.pop();
            count++;
            if(count == k) {
                res = root->val;
                break;
            }
            // 更新为右子树
            root = root->right;
        }
        return res;
    }
};
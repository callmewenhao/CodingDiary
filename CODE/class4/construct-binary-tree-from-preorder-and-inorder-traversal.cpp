// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* build(vector<int>& preorder, int preL, int preR, \
        vector<int>& inorder, int inL, int inR) {
        // recurse stop condition!
        if(preL > preR) return nullptr;
        // build root node!
        int val = preorder[preL];
        TreeNode* root = new TreeNode(val);
        // find left subTree size
        int rootIdxinIn = inL;
        while(inorder[rootIdxinIn] != val) {
            rootIdxinIn++;
        }
        int leftTreeSize = rootIdxinIn - inL;
        // build left subtree
        root->left = build(preorder, preL + 1, preL + leftTreeSize, inorder, inL, rootIdxinIn - 1);
        // build right subtree
        root->right = build(preorder, preL + leftTreeSize + 1, preR, inorder, rootIdxinIn + 1, inR);
        return root;
    }
public:
    // 递归方法
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};











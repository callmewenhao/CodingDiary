// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    TreeNode* build(vector<int>& preorder, int preL, int preR,\
        vector<int>& postorder, int posL, int posR) {
            // recurse stop condition
            if(preL > preR) return nullptr;
            if (preL == preR) { // 前中序也可以使用
                return new TreeNode(preorder[preL]);
            }
            // build root node
            int rootVal = preorder[preL];
            TreeNode* root = new TreeNode(rootVal);
            // find left subtree size
            int leftRootIdxInPos = posL;
            while(postorder[leftRootIdxInPos] != preorder[preL + 1]) {
                leftRootIdxInPos++;
            }
            int leftSize = leftRootIdxInPos - posL + 1;
            // build left sub tree
            root->left = build(preorder, preL + 1, preL + leftSize, postorder, posL, leftRootIdxInPos);
            // build right sub tree
            root->right = build(preorder, preL + leftSize + 1, preR, postorder, leftRootIdxInPos + 1, posR - 1);
            return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};















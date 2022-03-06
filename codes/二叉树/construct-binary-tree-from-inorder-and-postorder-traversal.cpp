/*
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
private:
    TreeNode* build(vector<int>& inorder, int inL, int inR, \
        vector<int>& postorder, int posL, int posR) {
        if(posL > posR) return nullptr;
        if(posL == posR) return new TreeNode(postorder[posL]);
        // 
        int rootVal = postorder[posR];
        TreeNode* root = new TreeNode(rootVal);
        // 
        int rootIdx = inL;
        while(inorder[rootIdx] != rootVal) {
            rootIdx++;
        }
        int leftSize = rootIdx - inL;
        //
        root->left = build(inorder, inL, rootIdx - 1, postorder, posL, posL + leftSize - 1);
        root->right = build(inorder, rootIdx + 1, inR, postorder, posL + leftSize, posR - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

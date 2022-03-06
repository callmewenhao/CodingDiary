// https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    // 采用构造二叉树的思路：先找根结点，之后找左右子树的范围
    TreeNode* build(vector<int>& preorder, int begin, int end) { // begin, end 是闭区间
        if(begin > end) return nullptr; // 迭代停止条件
        // 构造根节点
        int rootVal = preorder[begin];
        TreeNode* root = new TreeNode(rootVal);
        // 确定左右子树范围
        int idx = begin + 1;
        int leftSize = 0;
        while(idx <= end && preorder[idx] < rootVal) {
            idx++;
        }
        leftSize = idx - begin - 1;
        // 构造左右子树
        root->left = build(preorder, begin + 1, begin + leftSize);
        root->right = build(preorder, idx, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
};













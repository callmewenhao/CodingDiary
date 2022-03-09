// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> build(int begin, int end) {
        if(begin > end) {
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        // 遍历所有的根结点
        for(int i = begin; i <= end; i++) {
            // 所有左子树
            vector<TreeNode*> leftTrees = build(begin, i - 1);
            // 所有右子树
            vector<TreeNode*> rightTrees = build(i + 1, end);
            // 根节点和左右子树拼接
            for(auto& left : leftTrees) {
                for(auto& right : rightTrees) {
                    TreeNode* currentRoot = new TreeNode(i);
                    currentRoot->left = left;
                    currentRoot->right = right;
                    allTrees.push_back(currentRoot);
                }
            }
        }
        return allTrees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return build(1, n); 
    }
};


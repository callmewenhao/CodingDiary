//https://leetcode-cn.com/problems/find-duplicate-subtrees/
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
    unordered_map<string, int> hashMap;
    vector<TreeNode*> res;

    string findSameTree(TreeNode* root) {
        //  递归停止条件
        if(root == nullptr) return "#";
        // 将当前的树转换为字符串
        string leftTree = findSameTree(root->left);
        string rightTree = findSameTree(root->right);
        string currentTree = leftTree + "," + rightTree + "," + to_string(root->val);
        // 判断当前字符串是否出现过，如果出现过，且value=1，就说明出现相同子树
        if(hashMap.count(currentTree) > 0) {
            if(hashMap[currentTree] == 1)
                res.push_back(root);
        }
        // 更新hashMap
        hashMap[currentTree]++;
        return currentTree;
    }


public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       findSameTree(root);
       return res;
    }
};
// https://leetcode-cn.com/problems/maximum-binary-tree/
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
    TreeNode* build(vector<int>& nums, int begin, int end) {
        if(begin > end) return nullptr; // 递归停止的条件
    
        int idx = begin;
        int maxVal = nums[begin];
        for(int i = begin; i <= end; i++) {
            if(maxVal < nums[i]) {
                idx = i;
                maxVal = nums[i];
            }
        }

        TreeNode* root = new TreeNode(maxVal);
        root->left = build(nums, begin, idx - 1);
        root->right = build(nums, idx + 1, end);
        return root;
    }


public:
    // 递归解法
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};
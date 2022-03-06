/*
https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
升序数组转变为平衡二叉搜索树
平衡二叉搜索树的中序遍历是升序的，借助这点：数组的中心是根结点
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
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
    	/*
		在本函数中建立根结点，同时维护其左右指针
    	*/
        if(r < l) {  // 递归的结束条件
            return nullptr;
        }
        // 正常情况
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildTree(nums, l, m-1);
        root->right = buildTree(nums, m+1, r);
        return root;
    }
public:
    // 递归的方法
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};










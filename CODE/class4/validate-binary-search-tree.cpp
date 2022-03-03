/* https://leetcode-cn.com/problems/validate-binary-search-tree/ */
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
	// 递归解法
    bool isValidBST(TreeNode* root) {
        return recurse(root, nullptr, nullptr);
    }

    bool recurse(TreeNode* root, TreeNode* lower, TreeNode* upper){
        if(root == nullptr) return true;
        // 查当前结点
        if(lower != nullptr && root->val <= lower->val) return false;
        if(upper != nullptr && root->val >= upper->val) return false;
        // 查左右子树
        if(!recurse(root->left, lower, root)) return false;
        if(!recurse(root->right, root, upper)) return false;
        return true;
    }
    // 中序遍历解法
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true; // 异常情况
        
        long long inorder = (long long)INT_MIN - 1;
        stack<TreeNode*> nodeStack;

        while(!nodeStack.empty() || root != nullptr) {
            while(root != nullptr) {
                nodeStack.push(root);
                root = root->left;
            }
            // 维护root指针
            root = nodeStack.top();
            nodeStack.pop();
            // 升序判断
            if(inorder >= root->val) return false;
            inorder = root->val;
            // 维护root指针
            root = root->right;
        }
        return true;
    }
};





















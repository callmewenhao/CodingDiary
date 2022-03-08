/*
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // 借助层序遍历 
    Node* connect(Node* root) {
        // 特殊情况处理
        if(root == nullptr) return nullptr;
        
        // 层次遍历
        queue<Node*> myQueue;
        myQueue.push(root);

        while(!myQueue.empty()) {
            int qLen = myQueue.size();
            for(int i = 0; i < qLen; i++) {
                Node* node = myQueue.front();
                myQueue.pop();
                // 推入下一次遍历的结点
                if(node->left != nullptr) myQueue.push(node->left);
                if(node->right != nullptr) myQueue.push(node->right);
                // 对本层结点处理
                if(i < qLen - 1) node->next = myQueue.front();
                else node->next = nullptr;
            }
        }
        return root;
    }
};
















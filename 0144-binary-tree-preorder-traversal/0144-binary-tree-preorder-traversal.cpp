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
    void traverse(TreeNode* root, vector<int>& resultantVector){
        if(root == NULL){
            return;
        }

        stack<TreeNode*> stack;
        stack.push(root);

        while(!stack.empty()){
            TreeNode* tempNode = stack.top();
            stack.pop();

            resultantVector.push_back(tempNode->val);

            if(tempNode->right != NULL){
                stack.push(tempNode->right);
            }

            if(tempNode->left != NULL){
                stack.push(tempNode->left);
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> resultantVector;
        traverse(root, resultantVector);

        return resultantVector;
    }
};
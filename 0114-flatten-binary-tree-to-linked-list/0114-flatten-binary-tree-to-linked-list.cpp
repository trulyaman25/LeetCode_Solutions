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
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> assetStack;
        assetStack.push(root);

        while(!assetStack.empty()){
            TreeNode* currentNode = assetStack.top();
            assetStack.pop();

            if(currentNode->right) {
                assetStack.push(currentNode->right);
            }

            if(currentNode->left) {
                assetStack.push(currentNode->left);
            }
            
            if(!assetStack.empty()){
                currentNode->right = assetStack.top();
            }

            currentNode->left = NULL;
        }       
    }
};
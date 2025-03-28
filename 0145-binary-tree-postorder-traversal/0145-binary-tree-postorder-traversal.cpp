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
        if (root == NULL) return;

        stack<TreeNode*> stackOne;
        stack<TreeNode*> stackTwo;

        stackOne.push(root);
        while(!stackOne.empty()){
            TreeNode* tempNode = stackOne.top();
            stackOne.pop();

            stackTwo.push(tempNode);

            if(tempNode->left != NULL){
                stackOne.push(tempNode->left);
            }
            if(tempNode->right != NULL){
                stackOne.push(tempNode->right);
            }
        }

        while(!stackTwo.empty()){
            resultantVector.push_back(stackTwo.top()->val);
            stackTwo.pop();
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> resultantVector;
        traverse(root, resultantVector);

        return resultantVector;
    }
};
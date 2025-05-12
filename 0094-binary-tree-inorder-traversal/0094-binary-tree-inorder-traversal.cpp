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
    void morrisTraversal(TreeNode* pointer, vector<int>& resultantVector){
        while(pointer != NULL){
            if(pointer->left == NULL){
                resultantVector.push_back(pointer->val);
                pointer = pointer->right;
            } else {
                TreeNode* tempPointer = pointer->left;

                while(tempPointer->right && tempPointer->right != pointer){
                    tempPointer = tempPointer->right;
                }

                if(tempPointer->right == NULL){
                    tempPointer->right = pointer;
                    pointer = pointer->left;
                } else {
                    tempPointer->right = NULL;
                    resultantVector.push_back(pointer->val);
                    pointer = pointer->right;
                }
            }

        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultantVector;
        morrisTraversal(root, resultantVector);

        return resultantVector;
    }
};
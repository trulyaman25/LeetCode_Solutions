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
    int findHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        int height = max(leftHeight, rightHeight);

        return height + 1;
    }

    bool traverse(TreeNode* root){
        if(root == NULL){
            return true;
        }

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        if(abs(leftHeight - rightHeight) > 1){
            return false;
        }

        bool checkLeft = traverse(root->left);
        bool checkRight = traverse(root->right);

        if(!checkLeft || !checkRight) {
            return false;
        }

        return true;
    }

    bool isBalanced(TreeNode* root) {
        return traverse(root);
    }
};
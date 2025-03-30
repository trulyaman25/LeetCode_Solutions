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

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        int maxHeight = max(left, right);

        return maxHeight + 1;
    }

    void traverse(TreeNode* root, int& maxDiameter){
        if(root == NULL){
            return;
        }

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        int currentDiameter = leftHeight + rightHeight;
        maxDiameter = max(currentDiameter, maxDiameter);

        traverse(root->left, maxDiameter);
        traverse(root->right, maxDiameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        traverse(root, maxDiameter);

        return maxDiameter;
    }
};
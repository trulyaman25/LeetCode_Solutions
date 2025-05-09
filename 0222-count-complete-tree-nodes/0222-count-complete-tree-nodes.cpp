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
    int getLeftHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }

        return height;
    }

    int getRightHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if(leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return left + right + 1;
    }
};
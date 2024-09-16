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
    int traverse(TreeNode* root, int sum){
        if(root == NULL){
            return sum;
        }

        sum = traverse(root->left, sum);

        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            sum += root->left->val;
        }

        sum = traverse(root->right, sum);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return traverse(root, 0);
    }
};
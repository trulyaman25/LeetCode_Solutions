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
    int traverse(TreeNode* root, int& maxSum){
        if(root == NULL){
            return 0;
        }

        int left = max(0, traverse(root->left, maxSum));
        int right = max(0, traverse(root->right, maxSum));

        maxSum = max(left + right + root->val, maxSum);

        int maxLength = max(left, right);

        return root->val + maxLength;

    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        traverse(root, maxSum);

        return maxSum;
    }
};
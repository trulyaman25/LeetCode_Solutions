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
    bool traverse(TreeNode* root, long long minLimit, long long maxLimit){
        if(root == NULL){
            return true;
        }

        if(root->val >= maxLimit || root->val <= minLimit) {
            return false;
        }

        bool left = traverse(root->left, minLimit, root->val);
        bool right = traverse(root->right, root->val, maxLimit);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return traverse(root, LLONG_MIN, LLONG_MAX);
    }
};
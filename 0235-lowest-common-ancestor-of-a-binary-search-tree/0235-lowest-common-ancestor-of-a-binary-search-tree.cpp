/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* traverse(TreeNode* root, TreeNode* nodeOne, TreeNode* nodeTwo){
        if(root == NULL){
            return NULL;
        }

        int currentValue = root->val;

        if(currentValue < nodeOne->val && currentValue < nodeTwo->val){
            return traverse(root->right, nodeOne, nodeTwo);
        }
        
        if (currentValue > nodeOne->val && currentValue > nodeTwo->val){
            return traverse(root->left, nodeOne, nodeTwo);
        }

        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root, p, q);
    }
};
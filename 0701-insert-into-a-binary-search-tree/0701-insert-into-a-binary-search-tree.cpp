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
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        TreeNode* head = root;
        while(root){
            if(root->val > value){
                if(root->left){
                    root = root->left;
                } else {
                    root->left = new TreeNode(value);
                    break;
                }
            } else if (root->val < value){
                if(root->right){
                    root = root->right;
                } else {
                    root->right = new TreeNode(value);
                    break;
                }
            }
        }

        return head;
    }
};
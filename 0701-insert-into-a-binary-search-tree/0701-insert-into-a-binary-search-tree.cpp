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
    TreeNode* insertIntoBST(TreeNode* root, int targetValue) {
        TreeNode* targetNode = new TreeNode(targetValue);

        if(root == NULL){
            return targetNode;
        }

        TreeNode* head = root;

        while(root){
            int currentNode = root->val;

            if(currentNode > targetValue){
                if(root->left){
                    root = root->left;
                } else {
                    root->left = targetNode;
                    break;
                }
            } else {
                if(root->right){
                    root = root->right;
                } else {
                    root->right = targetNode;
                    break;
                }
            }
        }

        return head;
    }
};
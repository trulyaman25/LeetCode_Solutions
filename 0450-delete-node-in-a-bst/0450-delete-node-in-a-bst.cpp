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
    TreeNode* getLastNode(TreeNode* root){
        while(root->right){
            root = root->right;
        }

        return root;
    }

    TreeNode* getNode(TreeNode* targetNode){
        if(targetNode->left == NULL){
            return targetNode->right;
        } else if (targetNode->right == NULL){
            return targetNode->left;
        }

        TreeNode* rightNode = targetNode->right;
        TreeNode* leftNode = targetNode->left;
        TreeNode* lastRightNode = getLastNode(leftNode);
        lastRightNode->right = rightNode;

        return leftNode;
    }

    TreeNode* deleteNode(TreeNode* root, int targetValue) {
        if(root == NULL){
            return root;
        }

        TreeNode* head = root;

        int currentValue = root->val;

        if(currentValue == targetValue){
            return getNode(root);
        }

        while(root){
            currentValue = root->val;

            if(currentValue > targetValue){
                if(root->left && root->left->val == targetValue) {
                    root->left = getNode(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right && root->right->val == targetValue) {
                    root->right = getNode(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return head;
    }
};
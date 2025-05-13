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
        if(root->right == NULL){
            return root;
        }

        return getLastNode(root->right);
    }

    TreeNode* getNode(TreeNode* targetNode){
        if(targetNode == NULL){
            return targetNode;
        } else if (targetNode->right == NULL){
            return targetNode->left;
        }

        TreeNode* rightNode = targetNode->right;
        TreeNode* lastRightNode = getLastNode(targetNode->left);
        lastRightNode->right = rightNode;

        return targetNode->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }

        TreeNode* head = root;

        if(root->val == key){
            return getNode(root);
        }

        while(root){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = getNode(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right != NULL && root->right->val == key){
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
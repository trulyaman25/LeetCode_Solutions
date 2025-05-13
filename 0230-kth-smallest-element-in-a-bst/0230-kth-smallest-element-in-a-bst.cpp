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
    void traverse(TreeNode* root, int& result, int& position, bool& found){
        if(root == NULL || found){
            return;
        }

        traverse(root->left, result, position, found);

        position--;
        if(position == 0){
            result = root->val;
            found = true;
            return;
        }

        traverse(root->right, result, position, found);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        bool found = false;
        traverse(root, result, k, found);

        return result;
    }
};
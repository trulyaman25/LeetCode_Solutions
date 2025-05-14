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
    TreeNode* buildTree(vector<int>& preorder, int& index, int lowerLimit, int upperLimit){
        if(index >= preorder.size() || preorder[index] < lowerLimit || preorder[index] > upperLimit){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        root->left = buildTree(preorder, index, lowerLimit, root->val);
        root->right = buildTree(preorder, index, root->val, upperLimit);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int lowerLimit = INT_MIN;
        int upperLimit = INT_MAX;

        return buildTree(preorder, index, lowerLimit, upperLimit);
    }
};
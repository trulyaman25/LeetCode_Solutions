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
    TreeNode* getNode(
        vector<int>& inorder,
        int inorderStart,
        int inorderEnd,
        vector<int>& preorder,
        int preorderStart,
        int preorderEnd,
        unordered_map<int, int>& hashMap
    ){
        if(inorderStart > inorderEnd || preorderStart > preorderEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preorderStart]);

        int inorderRootIndex = hashMap[root->val];
        int leftClusterSize = inorderRootIndex - inorderStart;

        root->left = getNode(
            inorder, 
            inorderStart, 
            inorderRootIndex - 1, 
            preorder, 
            preorderStart + 1, 
            preorderStart + leftClusterSize, 
            hashMap
        );

        root->right = getNode(
            inorder, 
            inorderRootIndex + 1, 
            inorderEnd, 
            preorder, 
            preorderStart + leftClusterSize + 1, 
            preorderEnd, 
            hashMap
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < inorder.size(); i++){
            hashMap[inorder[i]] = i;
        }

        TreeNode* root = getNode(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, hashMap);

        return root;
    }
};
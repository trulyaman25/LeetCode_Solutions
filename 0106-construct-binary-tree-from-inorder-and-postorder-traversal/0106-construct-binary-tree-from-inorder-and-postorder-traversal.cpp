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
        vector<int>& postorder,
        int postorderStart,
        int postorderEnd,
        unordered_map<int, int>& hashMap
    ){
        if(inorderStart > inorderEnd || postorderStart > postorderEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postorderEnd]);

        int inorderRootIndex = hashMap[root->val];
        int leftClusterSize = inorderRootIndex - inorderStart;
        int rightClusterSize = inorderEnd - inorderRootIndex;

        root->left = getNode(
            inorder,
            inorderStart,
            inorderRootIndex - 1,
            postorder,
            postorderStart,
            postorderStart + leftClusterSize - 1,
            hashMap
        );

        root->right = getNode(
            inorder,
            inorderRootIndex + 1,
            inorderEnd,
            postorder,
            postorderEnd - rightClusterSize,
            postorderEnd - 1,
            hashMap
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < inorder.size(); i++){
            hashMap[inorder[i]] = i;
        }

        TreeNode* root = getNode(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hashMap);

        return root;
    }
};
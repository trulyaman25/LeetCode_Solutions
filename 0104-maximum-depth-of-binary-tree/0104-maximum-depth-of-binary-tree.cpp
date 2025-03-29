class Solution {
public:
    void traverse(TreeNode* root, int& maxDepth, int currentDepth){
        if(root == NULL){
            return;
        }

        maxDepth = max(maxDepth, currentDepth);
        traverse(root->left, maxDepth, currentDepth + 1);
        traverse(root->right, maxDepth, currentDepth + 1);
    }

    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        int currentDepth = 1;
        traverse(root, maxDepth, currentDepth);

        return maxDepth;
    }
};
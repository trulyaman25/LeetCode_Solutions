class Solution {
public:
    bool traverse(TreeNode* nodeOne, TreeNode* nodeTwo) {
        if (nodeOne == NULL && nodeTwo == NULL){
            return true;
        }
        if (nodeOne == NULL || nodeTwo == NULL){
            return false;
        }
        if (nodeOne->val != nodeTwo->val){
            return false;
        }

        return traverse(nodeOne->left, nodeTwo->left) && traverse(nodeOne->right, nodeTwo->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traverse(p, q);
    }
};
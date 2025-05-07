class Solution {
public:
    int getLeftHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }

    int getRightHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if(leftHeight == rightHeight){
            return pow(2, leftHeight) - 1;
        }

        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);

        return leftCount + rightCount + 1;
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resultantLevel = 0;
        int level = 0;

        queue<TreeNode*> assetQueue;
        assetQueue.push(root);

        while(!assetQueue.empty()){
            level++;
            
            int sumAtCurrentLevel = 0;
            for(int i = assetQueue.size(); i > 0; i--){
                TreeNode* node = assetQueue.front();
                assetQueue.pop();
                sumAtCurrentLevel += node->val;

                if(node->left != NULL){
                    assetQueue.push(node->left);
                }

                if(node->right != NULL){
                    assetQueue.push(node->right);
                }
            }

            if(maxSum < sumAtCurrentLevel){
                maxSum = sumAtCurrentLevel;
                resultantLevel = level;
            }
        }

        return resultantLevel;
    }
};
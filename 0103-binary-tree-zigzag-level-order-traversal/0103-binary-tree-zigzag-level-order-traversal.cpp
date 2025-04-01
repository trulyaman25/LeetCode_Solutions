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
    void traverse(TreeNode* root, vector<vector<int>>& resultantVector, bool changeDirection){
        if(root == NULL){
            return;
        }

        queue<TreeNode*> queue;
        queue.push(root);
        queue.push(NULL);

        vector<int> assetVector;

        while(!queue.empty()){
            TreeNode* tempNode = queue.front();
            queue.pop();

            if(tempNode == NULL){
                if(changeDirection){
                    reverse(assetVector.begin(), assetVector.end());
                    resultantVector.push_back(assetVector);
                    changeDirection = !changeDirection;
                } else {
                    resultantVector.push_back(assetVector);
                    changeDirection = !changeDirection;
                }

                if(!queue.empty()){
                    queue.push(NULL);
                }

                assetVector.clear();
            } else {
                assetVector.push_back(tempNode->val);
                if(tempNode->left != NULL){
                    queue.push(tempNode->left);
                }

                if(tempNode->right != NULL){
                    queue.push(tempNode->right);
                }
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>resultantVector;
        traverse(root, resultantVector, false);

        return resultantVector;
    }
};
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
    void levelOrderTraversal(TreeNode* node, vector<vector<int>>& resultantVector){
        if (!node){
            return;
        }

        queue<TreeNode*> queue;
        queue.push(node);
        queue.push(NULL);

        vector<int> dataVector;

        while(!queue.empty()){
            TreeNode* tempNode = queue.front();
            queue.pop();

            if(tempNode == NULL){
                resultantVector.push_back(dataVector);
                dataVector.clear();
                if(!queue.empty()){
                    queue.push(NULL);
                }
            } else {
                dataVector.push_back(tempNode->val);
                if(tempNode->left){
                    queue.push(tempNode->left);
                }

                if(tempNode->right){
                    queue.push(tempNode->right);
                }
            }
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultantVector;
        levelOrderTraversal(root, resultantVector);

        return resultantVector;
    }
};
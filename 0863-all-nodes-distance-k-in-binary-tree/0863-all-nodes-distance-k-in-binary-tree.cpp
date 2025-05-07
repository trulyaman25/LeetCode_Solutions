/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void fillParentMap(
        TreeNode* root, 
        unordered_map<TreeNode*, TreeNode*>& parentMap
    ){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            parentMap[root->left] = root;
        }
        if(root->right != NULL){
            parentMap[root->right] = root;
        }

        fillParentMap(root->left, parentMap);
        fillParentMap(root->right, parentMap);
    }

    void traverse(
        TreeNode* root, 
        unordered_map<TreeNode*, TreeNode*>& parentNode, 
        int currentDistance, 
        vector<int>& resultantVector
    ){
        queue<TreeNode*> assetQueue;
        assetQueue.push(root);
        assetQueue.push(NULL);

        unordered_map<TreeNode*, bool> visited;

        while(!assetQueue.empty() && currentDistance > 0){
            TreeNode* currentNode = assetQueue.front();
            assetQueue.pop();

            if(visited.count(currentNode) == 0){
                visited[currentNode] = true;
            }

            if(currentNode == NULL){
                currentDistance--;
                if(!assetQueue.empty()){
                    assetQueue.push(NULL);
                }
            } else{
                if(currentNode->left != NULL){
                    if(visited.count(currentNode->left) == 0){
                        visited[currentNode->left] = true;
                        assetQueue.push(currentNode->left);
                    }
                }
                if(currentNode->right != NULL){
                    if(visited.count(currentNode->right) == 0){
                        visited[currentNode->right] = true;
                        assetQueue.push(currentNode->right);
                    }
                }
                if(parentNode[currentNode] != NULL){
                    if(visited.count(parentNode[currentNode]) == 0){
                        visited[parentNode[currentNode]] = true;
                        assetQueue.push(parentNode[currentNode]);
                    }
                }
            }
        }

        while(!assetQueue.empty()){
            TreeNode* currentNode = assetQueue.front();
            assetQueue.pop();

            if(currentNode != NULL){
                resultantVector.push_back(currentNode->val);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        fillParentMap(root, parentMap);

        vector<int> resultantVector;
        traverse(target, parentMap, k, resultantVector);

        return resultantVector;
    }
};
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
    void fillParentMap(
        TreeNode* root, 
        unordered_map<TreeNode*, TreeNode*>& parentMap,
        TreeNode*& targetNode,
        int targetValue
    ){

    if(root == NULL){
        return;
    }

    if(root->val == targetValue){
        targetNode = root;
    }

    if(root->left){
        parentMap[root->left] = root;
        fillParentMap(root->left, parentMap, targetNode, targetValue);
    }

    if(root->right){
        parentMap[root->right] = root;
        fillParentMap(root->right, parentMap, targetNode, targetValue);
    }
}


    void traverse(
        TreeNode* root, 
        unordered_map<TreeNode*, TreeNode*>& parentNode,
        int& requiredTime
    ){
        queue<TreeNode*> assetQueue;
        assetQueue.push(root);
        assetQueue.push(NULL);

        unordered_map<TreeNode*, bool> visited;

        while(!assetQueue.empty()){
            TreeNode* selectedNode = assetQueue.front();
            assetQueue.pop();

            if(visited.count(selectedNode) == 0){
                visited[selectedNode] = true;
            }

            if(selectedNode == NULL){
                requiredTime++;
                if(!assetQueue.empty()){
                    assetQueue.push(NULL);
                }
            } else {
                if(selectedNode->left != NULL){
                    if(visited[selectedNode->left] == false){
                        visited[selectedNode->left] = true;
                        assetQueue.push(selectedNode->left);
                    }
                }
                if(selectedNode->right != NULL){
                    if(visited[selectedNode->right] == false){
                        visited[selectedNode->right] = true;
                        assetQueue.push(selectedNode->right);
                    }
                }

                if(parentNode[selectedNode] != NULL){
                    if(visited[parentNode[selectedNode]] == false){
                        visited[parentNode[selectedNode]] = true;
                        assetQueue.push(parentNode[selectedNode]);
                    }
                }
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* targetNode = NULL;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        fillParentMap(root, parentMap, targetNode, start);

        int requiredTime = 0;

        traverse(targetNode, parentMap, requiredTime);

        return requiredTime - 1;
    }
};
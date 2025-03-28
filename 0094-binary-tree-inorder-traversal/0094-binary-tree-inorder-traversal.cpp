class Solution {
public:
    void traverse(TreeNode* root, vector<int>& resultantVector){
        stack<TreeNode*> stack;
        TreeNode* tempNode = root;

        while(true){
            if(tempNode != NULL){
                stack.push(tempNode);
                tempNode = tempNode->left;
            } else {
                if(stack.empty()){
                    break;
                }
                
                tempNode = stack.top();
                resultantVector.push_back(tempNode->val);
                stack.pop();
                tempNode = tempNode->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultantVector;
        traverse(root, resultantVector);

        return resultantVector;
    }
};
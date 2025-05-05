class Solution {
public:
    void traverse(TreeNode* root, vector<vector<pair<TreeNode*, unsigned long long>>>& resultantVector, int& maxWidth){
        if(root == NULL){
            return;
        }

        queue<pair<TreeNode*, unsigned long long>> queue;
        queue.push(make_pair(root, 0));
        queue.push(make_pair(nullptr, 0));

        vector<pair<TreeNode*, unsigned long long>> storage;

        while(!queue.empty()){
            pair<TreeNode*, unsigned long long> selectedPair = queue.front();
            TreeNode* selectedNode = selectedPair.first;
            unsigned long long selectedIndex = selectedPair.second;
            queue.pop();

            if(selectedNode == nullptr){
                unsigned long long startIndex = storage[0].second;
                unsigned long long endIndex = storage.back().second;

                maxWidth = max((int)(endIndex - startIndex + 1), maxWidth);

                resultantVector.push_back(storage);
                storage.clear();

                if(!queue.empty()){
                    queue.push(make_pair(nullptr, 0));
                }
            } else {
                storage.push_back(make_pair(selectedNode, selectedIndex));

                if(selectedNode->left != nullptr){
                    queue.push(make_pair(selectedNode->left, 2ULL * (selectedIndex - 1) + 1));
                }
                if(selectedNode->right != nullptr){
                    queue.push(make_pair(selectedNode->right, 2ULL * (selectedIndex - 1) + 2));
                }
            }
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<pair<TreeNode*, unsigned long long>>> resultantVector;
        int maxWidth = 0;
        traverse(root, resultantVector, maxWidth);

        return maxWidth;
    }
};
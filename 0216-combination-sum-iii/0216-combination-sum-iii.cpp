class Solution {
public:
    void backtrack(int index, int targetSize, int targetSum, vector<int> &assetVector, vector<int> & dataVector, vector<vector<int>> &resultantVector){
        if(dataVector.size() == targetSize){
            if(targetSum == 0){
                resultantVector.push_back(dataVector);
            }
            return;
        }

        for(int i = index; i < assetVector.size(); i++){
            if(targetSum == 0){
                return;
            }
            dataVector.push_back(assetVector[i]);
            backtrack(i + 1, targetSize, targetSum - assetVector[i], assetVector, dataVector, resultantVector);
            dataVector.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> assetVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> dataVector;
        vector<vector<int>> resultantVector;

        backtrack(0, k, n, assetVector, dataVector, resultantVector);

        return resultantVector;
    }
};
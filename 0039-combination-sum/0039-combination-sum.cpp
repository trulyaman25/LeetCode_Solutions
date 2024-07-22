class Solution {
public:
    void findCombination(int index, int targetSum, vector<int>& assetVector, vector<int>& printingVector, vector<vector<int>>& resultantVector){
        if(index == assetVector.size()){
            if(targetSum == 0){
                resultantVector.push_back(printingVector);
            }
            return;
        }

        if(assetVector[index] <= targetSum){
            printingVector.push_back(assetVector[index]);
            findCombination(index, targetSum - assetVector[index], assetVector, printingVector, resultantVector);
            printingVector.pop_back();
        }

        findCombination(index + 1, targetSum, assetVector, printingVector, resultantVector);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> dataVector;
        vector<vector<int>> resultantVector;
        findCombination(0, target, candidates, dataVector, resultantVector);

        return resultantVector;
    }
};
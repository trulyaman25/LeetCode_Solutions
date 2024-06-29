class Solution {
public:

    void printSubSequence(int index, int targetSum, vector<int> &assetVector, vector<int> &printingVector, vector<vector<int>> &resultantVector){
        if(index == assetVector.size()){
            if(targetSum == 0){
                resultantVector.push_back(printingVector);
            }
            return;
        }

        if(assetVector[index] <= targetSum){
            printingVector.push_back(assetVector[index]);
            printSubSequence(index, targetSum - assetVector[index], assetVector, printingVector, resultantVector);
            printingVector.pop_back();
        }
        
        printSubSequence(index + 1, targetSum, assetVector, printingVector, resultantVector);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> dataVector;
        vector<vector<int>> resultantVector;
        printSubSequence(0, target, candidates, dataVector, resultantVector);

        return resultantVector;
    }
};
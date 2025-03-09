class Solution {
public:
    void findCombinationalSum(vector<int>& assetVector, int targetSum, vector<vector<int>>& resultantVector, vector<int>& tempVector, int index){
        if(index >= assetVector.size()){
            if(targetSum == 0){
                resultantVector.push_back(tempVector);
            }
            return;
        }

        if(targetSum >= assetVector[index]){
            tempVector.push_back(assetVector[index]);
            findCombinationalSum(assetVector, targetSum - assetVector[index], resultantVector, tempVector, index);
            tempVector.pop_back();
        }

        findCombinationalSum(assetVector, targetSum, resultantVector, tempVector, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tempVector;
        vector<vector<int>> resultantVector;
        findCombinationalSum(candidates, target, resultantVector, tempVector, 0);

        return resultantVector;
    }
};
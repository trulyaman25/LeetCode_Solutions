class Solution {
public:
    void combinationalSumTwo(vector<int>& assetVector, int targetSum, vector<vector<int>>& resultantVector, vector<int> tempVector, int index){
        if(targetSum == 0){
            resultantVector.push_back(tempVector);
            return;
        }

        for(int i = index; i < assetVector.size(); i++){
            if(i > index && assetVector[i] == assetVector[i - 1]){
                continue;
            }

            if(targetSum < assetVector[i]){
                break;
            }

            tempVector.push_back(assetVector[i]);
            combinationalSumTwo(assetVector, targetSum - assetVector[i], resultantVector, tempVector, i + 1);
            tempVector.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> tempVector;
        vector<vector<int>> resultantVector;
        combinationalSumTwo(candidates, target, resultantVector, tempVector, 0);

        return resultantVector;
    }
};
class Solution {
public:
    void findCombinations(int index, int targetSum, vector<int> &assetVector, vector<int> &dataVector, vector<vector<int>> &resultantVector){
        if(targetSum == 0){
            resultantVector.push_back(dataVector);
            return;
        }

        for(int i = index; i < assetVector.size(); i++){
            if(i > index && assetVector[i] == assetVector[i - 1]){
                continue;
            }

            if(targetSum < assetVector[i]){
                break;
            }

            dataVector.push_back(assetVector[i]);
            findCombinations(i + 1, targetSum - assetVector[i], assetVector, dataVector, resultantVector);
            dataVector.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> dataVector;
        vector<vector<int>> resultantVector;
        sort(candidates.begin(), candidates.end());
        findCombinations(0, target, candidates, dataVector, resultantVector);

        return resultantVector;
    }
};
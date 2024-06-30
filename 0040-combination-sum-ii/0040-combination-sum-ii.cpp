class Solution {
public:
    void findCombinations(int index, int targetSum, int currentSum, vector<int> &assetVector, vector<int> &dataVector, set<vector<int>> &resultantSet){
        if(currentSum > targetSum){
            return;
        }

        if(index == assetVector.size()){
            if(currentSum == targetSum){
                resultantSet.insert(dataVector);
            }
            return;
        } 

        dataVector.push_back(assetVector[index]);
        currentSum += assetVector[index];
        findCombinations(index + 1, targetSum, currentSum, assetVector, dataVector, resultantSet);

        currentSum -= dataVector.back();
        dataVector.pop_back();

        while (index + 1 < assetVector.size() && assetVector[index] == assetVector[index + 1]) {
            index++;
        }
        findCombinations(index + 1, targetSum, currentSum, assetVector, dataVector, resultantSet);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> dataVector;
        set<vector<int>> resultantSet;
        vector<vector<int>> resultantVector;

        sort(candidates.begin(), candidates.end());
        findCombinations(0, target, 0, candidates, dataVector, resultantSet);

        for(auto it : resultantSet){
            resultantVector.push_back(it);
        }

        return resultantVector;
    }
};
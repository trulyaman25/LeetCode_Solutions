class Solution {
public:
    void backtrack(int index, int target, vector<int>& assetVector, vector<int>& printingVector, vector<vector<int>>& resultantVector){
        if(target == 0){
            resultantVector.push_back(printingVector);
            return;
        }

        for(int i = index; i < assetVector.size(); i++){
            if(i > index && assetVector[i] == assetVector[i - 1]){
                continue;
            }

            if(target < assetVector[i]){
                break;
            }

            printingVector.push_back(assetVector[i]);
            backtrack(i + 1, target - assetVector[i], assetVector, printingVector, resultantVector);
            printingVector.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> dataVector;
        vector<vector<int>> resultantVector;

        sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, dataVector, resultantVector);

        return resultantVector;
    }
};
class Solution {
public:
    void call(vector<int>& assetVector, int targetSum, int currentSum, vector<vector<int>>& resultantVector, vector<int>& tempVector, int index){
        if(tempVector.size() == assetVector.size()){
            if(currentSum == targetSum){
                resultantVector.push_back(tempVector);
            }

            return;
        }

        tempVector.push_back(assetVector[index]);
        call(assetVector, targetSum, currentSum + assetVector[index], resultantVector, tempVector, index + 1);
        tempVector.pop_back();

        tempVector.push_back(assetVector[index] * -1);
        call(assetVector, targetSum, currentSum - assetVector[index], resultantVector, tempVector, index + 1);
        tempVector.pop_back();
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> resultantVector;
        vector<int> tempVector;
        call(nums, target, 0, resultantVector, tempVector, 0);

        return resultantVector.size();
    }
};
class Solution {
public:
    void findPermutations(vector<int>& assetVector, vector<vector<int>>& resultantVector, vector<int> tempVector, vector<bool>& takenStatus, int index){
        if(tempVector.size() == assetVector.size()){
            resultantVector.push_back(tempVector);
            return;
        }
        for(int i = 0; i < assetVector.size(); i++){
            if(!takenStatus[i]){
                tempVector.push_back(assetVector[i]);
                takenStatus[i] = !takenStatus[i];
                findPermutations(assetVector, resultantVector, tempVector, takenStatus, index + 1);
                takenStatus[i] = !takenStatus[i];
                tempVector.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tempVector;
        vector<vector<int>> resultantVector;
        vector<bool> takenStatus(nums.size(), false);
        findPermutations(nums, resultantVector, tempVector, takenStatus, 0);

        return resultantVector;
    }
};
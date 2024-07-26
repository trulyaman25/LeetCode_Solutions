class Solution {
public:
    void findPermutations(int index, vector<int> &assetVector, vector<int> &dataVector, vector<vector<int>> &resultantVector, vector<bool> check){
        if(index == assetVector.size()){
            resultantVector.push_back(dataVector);
            return;
        }

        for(int i = 0; i < assetVector.size(); i++){
            if(!check[i]){
                dataVector.push_back(assetVector[i]);
                check[i] = true;
                findPermutations(index + 1, assetVector, dataVector, resultantVector, check);
                dataVector.pop_back();
                check[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> dataVector;
        vector<vector<int>> resultantVector;
        vector<bool> check(nums.size(), false);
        findPermutations(0, nums, dataVector, resultantVector, check);

        return resultantVector;
    }
};
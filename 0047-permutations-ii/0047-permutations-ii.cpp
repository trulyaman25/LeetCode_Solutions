class Solution {
public:
    void findPermutations(vector<int>& assetVector, vector<vector<int>>& resultantVector, vector<int>& tempVector, vector<bool>& isTaken ){
        if(tempVector.size() == assetVector.size()){
            resultantVector.push_back(tempVector);
            return;
        }

        for(int i = 0; i < assetVector.size(); i++){
            if (isTaken[i] || (i > 0 && assetVector[i] == assetVector[i - 1] && !isTaken[i - 1])) {
                continue;
            }
            
            isTaken[i] = true;
            tempVector.push_back(assetVector[i]);
            findPermutations(assetVector, resultantVector, tempVector, isTaken);
            tempVector.pop_back();
            isTaken[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tempVector;
        vector<vector<int>> resultantVector;
        vector<bool> isTaken (nums.size(), false);
        
        sort(nums.begin(), nums.end());

        findPermutations(nums, resultantVector, tempVector, isTaken);

        return resultantVector;
    }
};
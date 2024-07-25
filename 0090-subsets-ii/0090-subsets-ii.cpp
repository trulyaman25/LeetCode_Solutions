class Solution {
public:
    void findSubSets(int index, vector<int>& assetVector, vector<int>& dataVector, vector<vector<int>>& resultantVector){
        resultantVector.push_back(dataVector);

        for(int i = index; i < assetVector.size(); i++){
            if(i != index && assetVector[i] == assetVector[i - 1]){
                continue;
            }

            dataVector.push_back(assetVector[i]);
            findSubSets(i + 1, assetVector, dataVector, resultantVector);
            dataVector.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> dataVector;
        vector<vector<int>> resultantVector;
        sort(nums.begin(), nums.end());
        findSubSets(0, nums, dataVector, resultantVector);

        return resultantVector;
    }
};
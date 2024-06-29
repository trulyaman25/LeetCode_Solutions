class Solution {
public:
    void findCombinations(int index, int targetSize, vector<int> &assetVector, vector<int> dataVector, vector<vector<int>> &resultantVector){
        if(index == assetVector.size()){
            if(dataVector.size() == targetSize){
                resultantVector.push_back(dataVector);
            }
            return;
        }

        dataVector.push_back(assetVector[index]);
        findCombinations(index + 1, targetSize, assetVector, dataVector, resultantVector);

        dataVector.pop_back();
        findCombinations(index + 1, targetSize, assetVector, dataVector, resultantVector);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> assetVector;
        for(int i = 1; i <= n; i++){
            assetVector.push_back(i);
        }

        vector<int> dataVector;
        vector<vector<int>> resultantVector;
        findCombinations(0, k, assetVector, dataVector, resultantVector);

        return resultantVector;
    }
};
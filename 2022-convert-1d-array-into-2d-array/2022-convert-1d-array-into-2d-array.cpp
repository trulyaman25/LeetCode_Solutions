class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()){
            return {};
        }

        vector<vector<int>> resultantVector;
        vector<int> dataVector;
        for(int i = 0; i < original.size(); i++){
            dataVector.push_back(original[i]);
            if(dataVector.size() == n){
                resultantVector.push_back(dataVector);
                dataVector.clear();
            }
        }

        return resultantVector;
    }
};
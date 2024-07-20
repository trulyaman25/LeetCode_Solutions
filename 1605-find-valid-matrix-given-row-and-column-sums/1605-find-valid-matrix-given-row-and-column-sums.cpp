class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> resultantVector;
        for(int i = 0; i < rowSum.size(); i++){
            vector<int> dataVector;
            for(int j = 0; j < colSum.size(); j++){
                int targetValue = min(rowSum[i], colSum[j]);
                dataVector.push_back(targetValue);

                rowSum[i] = rowSum[i] - targetValue;
                if(rowSum[i] < 0){
                    rowSum[i] = 0;
                }
                
                colSum[j] = colSum[j] - targetValue;
                if(colSum[j] < 0){
                    colSum[j] = 0;
                }
            }
            resultantVector.push_back(dataVector);
        }

        return resultantVector;
    }
};
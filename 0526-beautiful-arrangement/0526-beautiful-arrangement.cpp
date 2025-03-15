class Solution {
public:
    void call(
        vector<int>& assetVector,
        vector<bool>& visited,
        vector<vector<int>>& resultantVector,
        vector<int>& tempVector,
        int& beautifulCount
    ){
        if(tempVector.size() == assetVector.size() - 1){
            resultantVector.push_back(tempVector);
            beautifulCount++;
            return;
        }

        for(int i = 1; i < assetVector.size(); i++){
            if(!visited[i]) {
                tempVector.push_back(i);
                visited[i] = true;
                if(tempVector.back() % tempVector.size() == 0 || tempVector.size() % tempVector.back() == 0){
                    call(assetVector, visited, resultantVector, tempVector, beautifulCount);
                }
                visited[i] = false;
                tempVector.pop_back();
            }
        }
    }

    int countArrangement(int n) {
        vector<int> assetVector;
        for(int i = 0; i <= n; i++){
            assetVector.push_back(i);
        }

        vector<vector<int>> resultantVector;
        vector<bool> visited(assetVector.size(), false);
        vector<int> tempVector(1, 0);
        
        int beautifulCount = 0;
        call(assetVector, visited, resultantVector, tempVector, beautifulCount);

        for(int i = 0; i < resultantVector.size(); i++){
            for(int j = 0; j < resultantVector[i].size(); j++){
                cout << resultantVector[i][j] << " ";
            }
            cout << endl;
        }

        return beautifulCount;
    }
};
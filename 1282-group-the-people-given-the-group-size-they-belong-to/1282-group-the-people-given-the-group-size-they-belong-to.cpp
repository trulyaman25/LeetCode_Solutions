class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hashMap;
        for(int i = 0; i < groupSizes.size(); i++) {
            hashMap[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> resultantVector;
        for(auto it : hashMap){
            int groupSize = it.first;
            vector<int> &tempVector = it.second;
            for(int i = 0 ; i < tempVector.size(); i += groupSize){
                vector<int> tempStorage(tempVector.begin() + i, tempVector.begin() + i + groupSize);
                resultantVector.push_back(tempStorage);
            }
        }

        return resultantVector;
    }
};

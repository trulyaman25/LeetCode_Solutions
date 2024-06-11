class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < arr1.size(); i++){
            hashMap[arr1[i]]++;
        }

        vector<int> resultantVector;
        for(int i = 0; i < arr2.size(); i++){
            int value = arr2[i];
            auto it = hashMap.find(value);
            if(it != hashMap.end()){
                while(it->second > 0){
                    resultantVector.push_back(it->first);
                    it->second--;
                }
            }
        }

        for(auto it : hashMap){
            if(it.second > 0){
                while(it.second > 0){
                    resultantVector.push_back(it.first);
                    it.second--;
                }
            }
        }

        return resultantVector;
    }
};
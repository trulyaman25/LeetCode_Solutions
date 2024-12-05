class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < arr.size(); i++){
            hashMap[arr[i]]++;
        }

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0 && hashMap[arr[i]] == 1){
                continue;
            }
            if(hashMap.count(arr[i] * 2) == 1){
                return true;
            }
        }
        
        return false;
    }
};
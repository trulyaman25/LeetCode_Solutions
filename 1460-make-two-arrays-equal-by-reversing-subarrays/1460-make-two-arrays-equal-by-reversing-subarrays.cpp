class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < target.size(); i++){
            hashMap[target[i]]++;
        }

        for(int i = 0; i < arr.size(); i++){
            if(hashMap.count(arr[i]) == 0){
                return false;
            } else {
                if(hashMap[arr[i]] > 0){
                    hashMap[arr[i]]--;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hashMap;
        for(int i = 0; i < arr.size(); i++){
            hashMap[arr[i]]++;
        }

        vector<string> vector;

        for(auto it : hashMap){
            if(it.second == 1){
                vector.push_back(it.first);
            }
        }

        for(int i = vector.size() - 1; i >= 0; i--){
            k--;
            if(k == 0){
                return vector[i];
            }
        }

        return "";
    }
};
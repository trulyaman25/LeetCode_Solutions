class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> resultantVector;
        int totalSubset = pow(2, nums.size());
        for(int i = 0; i < totalSubset; i++){
            vector<int> tempStorage;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    tempStorage.push_back(nums[j]);
                }
            }
            resultantVector.push_back(tempStorage);
        }
        return resultantVector;
    }
};
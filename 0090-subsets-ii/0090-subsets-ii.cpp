class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> set;
        int totalSubsets = pow(2, nums.size());
        for(int i = 0; i < totalSubsets; i++){
            vector<int> rowVector;
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){
                    rowVector.push_back(nums[j]);
                }
            }
            sort(rowVector.begin(), rowVector.end());
            set.emplace(rowVector);
        }

        vector<vector<int>> resultantVector;
        for(auto it : set){
            resultantVector.push_back(it);
        }

        return resultantVector;
    }
};
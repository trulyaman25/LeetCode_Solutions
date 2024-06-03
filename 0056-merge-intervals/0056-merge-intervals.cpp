class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> resultantVector;
        resultantVector.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(resultantVector.back()[1] >= nums[i][0]){
                resultantVector.back()[1] = max(resultantVector.back()[1], nums[i][1]);
            } else {
                resultantVector.push_back(nums[i]);
            }
        }

        return resultantVector;
    }
};
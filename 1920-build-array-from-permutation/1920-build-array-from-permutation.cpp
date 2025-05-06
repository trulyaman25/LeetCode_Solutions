class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> resultantVector;
        for(int i = 0; i < nums.size(); i++){
            resultantVector.push_back(nums[nums[i]]);
        }
        return resultantVector;
    }
};
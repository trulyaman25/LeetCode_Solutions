class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int minDifference = INT_MAX;
        vector<vector<int>> resultantVector;
        for(int i = 1; i < nums.size(); i++){
            int difference = abs(nums[i] - nums[i - 1]);
            minDifference = min(difference, minDifference);
        }

        for(int i = 1; i < nums.size(); i++){
            int difference = abs(nums[i] - nums[i - 1]);
            if(difference == minDifference){
                resultantVector.push_back({nums[i - 1], nums[i]});
            }
        }

        return resultantVector;
    }
};
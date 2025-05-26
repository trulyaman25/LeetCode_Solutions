class Solution {
public:
    bool checkPartition(vector<int>& assetVector, int index, int currentSum, int sum, vector<vector<int>>& dp){
        if(currentSum == sum / 2){
            return true;
        }

        if(index == 0){
            if(currentSum - assetVector[index] == sum / 2){
                return true;
            }

            return false;
        }

        if(dp[index][currentSum] != -1){
            return dp[index][currentSum];
        }

        bool pick = false;
        if(currentSum - assetVector[index] >= sum / 2){
            pick = checkPartition(assetVector, index - 1, currentSum - assetVector[index], sum, dp);
        }

        bool notPick = checkPartition(assetVector, index - 1, currentSum, sum, dp);

        return dp[index][currentSum] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }

        if(sum % 2 != 0){
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return checkPartition(nums, nums.size() - 1, sum, sum, dp);
    }
};
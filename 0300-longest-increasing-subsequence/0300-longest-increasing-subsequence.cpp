class Solution {
public:
    int getLIS(vector<int>& nums, int index, int lastIndex, vector<vector<int>>& dp){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index][lastIndex + 1] != -1){
            return dp[index][lastIndex + 1];
        }

        int pick = 0;
        if(lastIndex == -1 || nums[index] > nums[lastIndex]){
            pick = 1 + getLIS(nums, index + 1, index, dp);
        }

        int notPick = getLIS(nums, index + 1, lastIndex, dp);

        return dp[index][lastIndex + 1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return getLIS(nums, 0, -1, dp);
    }
};
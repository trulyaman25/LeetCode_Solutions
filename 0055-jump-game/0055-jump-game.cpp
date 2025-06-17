class Solution {
public:
    bool traverse(vector<int>& nums, int index, vector<int>& dp){
        if(index >= nums.size()){
            return false;
        }

        if(index == nums.size() - 1){
            return true;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int maxJump = nums[index];
        for(int i = 1; i <= maxJump; i++){
            int nextIndex = index + i;
            if(nextIndex < nums.size()){
                if(traverse(nums, nextIndex, dp)){
                    dp[nextIndex] = 1;
                    return true;
                } else {
                    dp[nextIndex] = 0;
                }
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return traverse(nums, 0, dp);
    }
};
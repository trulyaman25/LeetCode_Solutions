class Solution {
public:
    int traverse(vector<int>& nums, int index, vector<int>& dp){
        if(index >= nums.size()){
            return 1e9;
        }

        if(index == nums.size() - 1){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int minJumps = INT_MAX - 1;
        for(int i = 1; i <= nums[index] && index + i < nums.size(); i++){
            int currentJumpCount = traverse(nums, index + i, dp) + 1;
            minJumps = min(currentJumpCount, minJumps);
        }

        return dp[index] = minJumps;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return traverse(nums, 0, dp);
    }
};
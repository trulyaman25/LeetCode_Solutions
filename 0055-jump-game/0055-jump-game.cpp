class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;

        for(int i = 0; i < dp.size(); i++){
            if(!dp[i]){
                continue;
            }

            int maxJump = nums[i];
            for(int j = 1; j <= maxJump && i + j < nums.size(); j++){
                dp[i + j] = true;
            }
        }

        return dp.back();
    }
};
class Solution {
public:
    int getMin(vector<int>& assetVector, int index, int amount, vector<vector<int>>& dp){
        if(amount == 0){
            return 0;
        }

        if(index < 0){
            return INT_MAX - 1;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int pick = INT_MAX;
        if(assetVector[index] <= amount){
            pick = getMin(assetVector, index, amount - assetVector[index], dp) + 1;
        }

        int notPick = getMin(assetVector, index - 1, amount, dp);

        return dp[index][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int result = getMin(coins, coins.size() - 1, amount, dp);
        if(result == INT_MAX - 1){
            return -1;
        }

        return result;
    }
};
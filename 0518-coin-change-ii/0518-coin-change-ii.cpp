class Solution {
public:
    int getCoins(vector<int>& coins, int index, int remainingAmount, vector<vector<int>>& dp){
        if(index == 0){
            if(remainingAmount % coins[index] == 0){
                return 1;
            }

            return 0;
        }

        if(dp[index][remainingAmount] != -1){
            return dp[index][remainingAmount];
        }

        int pick = 0;
        if(remainingAmount >= coins[index]){
            pick = getCoins(coins, index, remainingAmount - coins[index], dp);
        }

        int notPick = getCoins(coins, index - 1, remainingAmount, dp);

        return dp[index][remainingAmount] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return getCoins(coins, coins.size() - 1, amount, dp);
    }
};
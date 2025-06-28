class Solution {
public:
    int getProfit(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        if(buy){
            int buyStock = getProfit(prices, index + 1, false, dp) - prices[index];
            int notBuyStock = getProfit(prices, index + 1, true, dp);

            return dp[index][buy] = max(buyStock, notBuyStock);

        } else {
            int sellStock = prices[index] + getProfit(prices, index + 1, true, dp);
            int notSellStock = getProfit(prices, index + 1, false, dp);

            return dp[index][buy] = max(sellStock, notSellStock);
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return getProfit(prices, 0, true, dp);
    }
};
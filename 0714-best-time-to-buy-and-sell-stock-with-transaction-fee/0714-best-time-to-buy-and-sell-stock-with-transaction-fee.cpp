class Solution {
public:
    int getProfit(vector<int>& prices, int index, bool buy, int fees, vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        if(buy){
            int buyStock = -prices[index] + getProfit(prices, index + 1, false, fees, dp);
            int notBuyStock = getProfit(prices, index + 1, true, fees, dp);

            return dp[index][buy] = max(buyStock, notBuyStock);
        } else {
            int sellStock = prices[index] - fees + getProfit(prices, index + 1, true, fees, dp);
            int notSellStock = getProfit(prices, index + 1, false, fees, dp);

            return dp[index][buy] = max(sellStock, notSellStock);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return getProfit(prices, 0, true, fee, dp);
    }
};
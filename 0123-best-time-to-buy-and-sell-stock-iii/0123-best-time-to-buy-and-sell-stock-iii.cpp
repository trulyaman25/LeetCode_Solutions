class Solution {
public:
    int getProfit(vector<int>& prices, int index, bool buy, int cap, vector<vector<vector<int>>>& dp){
        if(index >= prices.size() || cap <= 0){
            return 0;
        }

        if(dp[index][buy][cap] != -1){
            return dp[index][buy][cap];
        }

        if(buy){
            int buyStock = -prices[index] + getProfit(prices, index + 1, false, cap, dp);
            int notBuyStock = getProfit(prices, index + 1, true, cap, dp);

            return dp[index][buy][cap] = max(buyStock, notBuyStock);
        } else {
            int sellStock = prices[index] + getProfit(prices, index + 1, true, cap - 1, dp);
            int notSellStock = getProfit(prices, index + 1, false, cap, dp);

            return dp[index][buy][cap] = max(sellStock, notSellStock);
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return getProfit(prices, 0, true, 2, dp);
    }
};
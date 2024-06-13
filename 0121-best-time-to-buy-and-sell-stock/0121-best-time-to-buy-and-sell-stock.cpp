class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1){
            return 0;
        }

        int profit = 0;
        int maxProfit = INT_MIN;

        for(int i = 1; i < prices.size(); i++){
            profit += prices[i] - prices[i - 1];
            maxProfit = max(maxProfit, profit);

            if(profit < 0){
                profit = 0;
            }
        }

        return max(maxProfit, 0);
    }
};
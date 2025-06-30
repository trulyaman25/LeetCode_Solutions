class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(2, 0);

        for(int i = prices.size() - 1; i >= 0; i--){
            vector<int> currentDP(2, 0);
            for(int j = 0; j < 2; j++){
                if(j){
                    currentDP[j] = max(-prices[i] + dp[0], dp[1]);
                } else {
                    currentDP[j] = max(prices[i] - fee + dp[1], dp[0]);
                }
            }

            dp = currentDP;
        }

        return dp.back();
    }
};
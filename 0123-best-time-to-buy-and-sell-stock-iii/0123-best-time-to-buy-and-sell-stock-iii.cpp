class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        
        for(int i = prices.size() - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 1; k <= 2; k++){
                    if(j){
                        dp[j][k] = max(-prices[i] + dp[0][k], dp[1][k]);
                    } else {
                        dp[j][k] = max(prices[i] + dp[1][k - 1], dp[0][k]);
                    }
                }
            }
        }

        return dp[1][2];
    }
};
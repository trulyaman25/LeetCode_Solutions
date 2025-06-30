class Solution {
public:
    int maxProfit(int threshold, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(threshold + 1, 0));
        
        for(int i = prices.size() - 1; i >= 0; i--){
            vector<vector<int>> currentDP(2, vector<int>(threshold + 1, 0));
            for(int j = 0; j < 2; j++){
                for(int k = 1; k <= threshold; k++){
                    if(j){
                        currentDP[j][k] = max(-prices[i] + dp[0][k], dp[1][k]);
                    } else {
                        currentDP[j][k] = max(prices[i] + dp[1][k - 1], dp[0][k]);
                    }
                }
            }

            dp = currentDP;
        }

        return dp[1].back();
    }
};
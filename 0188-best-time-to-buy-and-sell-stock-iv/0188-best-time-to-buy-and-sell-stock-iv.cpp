class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for(int i = prices.size() - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                for(int k = 1; k <= 2; k++){
                    if(j){
                        dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                    } else {
                        dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};
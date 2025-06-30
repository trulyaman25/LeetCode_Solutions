class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> previousDP(2, vector<int>(3, 0));
        for(int i = prices.size() - 1; i >= 0; i--){
            vector<vector<int>> currentDP(2, vector<int>(3, 0));
            for(int j = 0; j < 2; j++){
                for(int k = 1; k <= 2; k++){
                    if(j){
                        currentDP[j][k] = max(-prices[i] + previousDP[0][k], previousDP[1][k]);
                    } else {
                        currentDP[j][k] = max(prices[i] + previousDP[1][k - 1], previousDP[0][k]);
                    }
                }
            }
            previousDP = currentDP;
        }

        return previousDP[1][2];
    }
};
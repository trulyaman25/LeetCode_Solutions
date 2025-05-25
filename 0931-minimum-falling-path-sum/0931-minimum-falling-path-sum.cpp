class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int side = matrix.size();
        vector<vector<int>> dp(side, vector<int>(side, INT_MAX));

        for(int i = 0; i < side; i++){
            dp[side - 1][i] = matrix[side - 1][i];
        }

        for(int row = side - 2; row >= 0; row--){
            for(int column = 0; column < side; column++){
                int down = dp[row + 1][column];

                int left = INT_MAX;
                if(column - 1 >= 0){
                    left = dp[row + 1][column - 1];
                }

                int right = INT_MAX;
                if(column + 1 < side){
                    right = dp[row + 1][column + 1];
                }

                dp[row][column] = matrix[row][column] + min({left, down, right});
            }
        }

        int minSum = INT_MAX;
        for(int i = 0; i < side; i++){
            minSum = min(dp[0][i], minSum);
        }

        return minSum;
    }
};
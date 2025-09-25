class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.back().size(), INT_MIN));

        dp.back() = grid.back();

        for(int row = grid.size() - 2; row >= 0; row--){
            for(int column = 0; column < grid[row].size(); column++){
                int straight = dp[row + 1][column] + grid[row][column];
                int diagonal = dp[row + 1][column + 1] + grid[row][column];

                dp[row][column] = min(straight, diagonal);
            }
        }

        return dp[0][0];
    }
};
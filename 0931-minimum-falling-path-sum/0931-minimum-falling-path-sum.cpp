class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int side = matrix.size();
        vector<int> previousDP(matrix.back());

        for(int row = side - 2; row >= 0; row--){
            vector<int> currentDP(side, INT_MAX);
            for(int column = 0; column < side; column++){
                int left = INT_MAX;
                if(column - 1 >= 0){
                    left = previousDP[column - 1];
                }

                int right = INT_MAX;
                if(column + 1 < side){
                    right = previousDP[column + 1];
                }

                int down = previousDP[column];

                currentDP[column] = matrix[row][column] + min({left, down, right});
            }

            previousDP = currentDP;
        }
        
        int minSum = INT_MAX;
        for(auto it : previousDP){
            minSum = min(it, minSum);
        }

        return minSum;
    }
};
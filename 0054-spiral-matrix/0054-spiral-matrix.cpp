class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int totalElements = rows * columns;

        vector<int> resultantVector;

        bool invertRows = false;
        bool invertColumns = false;

        for (int round = 0; round < (min(rows, columns) + 1) / 2; round++){
            for(int column = round; column < columns - round && resultantVector.size() < totalElements; column++){
                resultantVector.push_back(grid[round][column]);
            }
            for(int row = round + 1; row < rows - round && resultantVector.size() < totalElements; row++){
                resultantVector.push_back(grid[row][columns - round - 1]);
            }
            for(int column = columns - round - 2; column >= round && resultantVector.size() < totalElements; column--){
                resultantVector.push_back(grid[rows - round - 1][column]);
            }
            for(int row = rows - round - 2; row >= round + 1 && resultantVector.size() < totalElements; row--){
                resultantVector.push_back(grid[row][round]);
            }
        }

        return resultantVector;
    }
};
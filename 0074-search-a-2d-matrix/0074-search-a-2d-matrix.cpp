class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startRow = 0;
        int endRow = matrix.size() - 1;
        int suspectedRow = -1;

        if(startRow == endRow){
            suspectedRow = startRow;
        } else {
            while(startRow <= endRow){
                int midRow = startRow + (endRow - startRow) / 2;
                if(matrix[midRow][0] <= target && matrix[midRow][matrix[0].size() - 1] >= target){
                    suspectedRow = midRow;
                    break;
                } else if(matrix[midRow][0] > target){
                    endRow = midRow - 1;
                } else if(matrix[midRow][matrix[0].size() - 1] < target){
                    startRow = midRow + 1;
                }
            }
        }


        int low = 0;
        int high = matrix[0].size() - 1;
        if(suspectedRow == -1){
            return false;
        } else {
            while(low <= high){
                int midIndex = low + (high - low) / 2;
                if(matrix[suspectedRow][midIndex] == target){
                    return true;
                } else if (matrix[suspectedRow][midIndex] > target){
                    high = midIndex - 1;
                } else {
                    low = midIndex + 1;
                }
            }
        }
        
        return false;
    }
};
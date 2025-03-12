class Solution {
public:
    bool checkIndex(vector<vector<char>>& board, int row, int column, int totalRows, int totalColumns){
        char indexValue = board[row][column];
        
        int currentRow = row;
        int currentColumn = column;
        while(currentColumn < totalColumns){
            if(currentColumn != column && board[currentRow][currentColumn] == indexValue){
                return false;
            }
            currentColumn++;
        }

        currentRow = row;
        currentColumn = column;
        
        while(currentRow < totalRows){
            if(currentRow != row && board[currentRow][currentColumn] == indexValue){
                return false;
            }
            currentRow++;
        }
        
        int startRow = (row / 3) * 3;
        int startCol = (column / 3) * 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int newRow = startRow + i;
                int newColumn = startCol + j;
                if(newRow != row && newColumn != column){
                    if(board[newRow][newColumn] == indexValue){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int totalRows = board.size();
        int totalColumns = totalRows;

        vector<pair<int, int>> assetVector;
        for(int rows = 0; rows < totalRows; rows++){
            for(int columns = 0; columns < totalColumns; columns++){
                if(board[rows][columns] != '.'){
                    assetVector.push_back(make_pair(rows, columns));
                }
            }
        }

        for(int i = 0; i < assetVector.size(); i++){
            if(!checkIndex(board, assetVector[i].first, assetVector[i].second, totalRows, totalColumns)){
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool valid(vector<vector<char>>& board, int row, int column, char value){
        for(int currentColumn = 0; currentColumn < 9; currentColumn++){
            if(board[row][currentColumn] == value){
                return false;
            }
        }
        

        for(int currentRow = 0; currentRow < 9; currentRow++){
            if(board[currentRow][column] == value){
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startColumn = (column / 3) * 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int newRow = startRow + i;
                int newColumn = startColumn + j;
                if(board[newRow][newColumn] == value){
                    return false;
                }
            }
        }

        return true;
    }

    bool completeSudoku(vector<vector<char>>& board){
        for(int row = 0; row < board.size(); row++){
            for(int column = 0; column < board[row].size(); column++){
                if(board[row][column] == '.'){
                    for(char i = '1'; i <= '9'; i++){
                        if(valid(board, row, column, i)){
                            board[row][column] = i;

                            if(completeSudoku(board) == true){
                                return true;
                            } else {
                                board[row][column] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        completeSudoku(board);
    }
};
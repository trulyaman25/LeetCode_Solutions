class Solution {
public:
    void findSolution(vector<vector<string>>& resultantVector,
                      vector<string>& chessBoard,
                      int side, 
                      int column, 
                      vector<int>& rowCheck, 
                      vector<int>& upperDiagonalCheck, 
                      vector<int>& lowerDiagonalCheck
    ){

        if(column == side){
            resultantVector.push_back(chessBoard);
            return;
        }

        for(int row = 0; row < side; row++){
            if(rowCheck[row] == 0 && upperDiagonalCheck[row + column] == 0 && lowerDiagonalCheck[(side - 1) + (column - row)] == 0){
                chessBoard[row][column] = 'Q';

                rowCheck[row] = 1;
                upperDiagonalCheck[row + column] = 1;
                lowerDiagonalCheck[(side - 1) + (column - row)] = 1;

                findSolution(resultantVector, chessBoard, side, column + 1, rowCheck, upperDiagonalCheck, lowerDiagonalCheck);

                rowCheck[row] = 0;
                upperDiagonalCheck[row + column] = 0;
                lowerDiagonalCheck[(side - 1) + (column - row)] = 0;

                chessBoard[row][column] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> resultantVector;
        vector<string> chessBoard;
        string chessBoardRow(n, '.');

        for(int i = 0; i < n; i++){
            chessBoard.push_back(chessBoardRow);
        }

        vector<int> rowCheck(n, 0);
        vector<int> upperDiagonalCheck(2*n - 1, 0);
        vector<int> lowerDiagonalCheck(2*n - 1, 0);

        findSolution(resultantVector, chessBoard, n, 0, rowCheck, upperDiagonalCheck, lowerDiagonalCheck);

        return resultantVector.size();
    }
};
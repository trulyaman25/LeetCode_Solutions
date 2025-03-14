class Solution {
public:
    bool call(string& word, vector<vector<char>>& board, vector<vector<bool>>& visited, int totalRows, int totalColumns, int row, int column, int index){
        if(index == word.length()){
            return true;
        }

        visited[row][column] = true;

        if(row - 1 >= 0 && !visited[row - 1][column] && board[row - 1][column] == word[index]){
            if(call(word, board, visited, totalRows, totalColumns, row - 1, column, index + 1)){
                return true;
            }
        }

        if(column + 1 < totalColumns && !visited[row][column + 1] && board[row][column + 1] == word[index]){
            if(call(word, board, visited, totalRows, totalColumns, row, column + 1, index + 1)){
                return true;
            }
        }

        if(row + 1 < totalRows && !visited[row + 1][column] && board[row + 1][column] == word[index]){
            if(call(word, board, visited, totalRows, totalColumns, row + 1, column, index + 1)){
                return true;
            }
        }

        if(column - 1 >= 0 && !visited[row][column - 1] && board[row][column - 1] == word[index]){
            if(call(word, board, visited, totalRows, totalColumns, row, column - 1, index + 1)){
                return true;
            }
        }

        visited[row][column] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int totalRows = board.size();
        int totalColumns = board[0].size();
        char startChar = word[0];

        for(int row = 0; row < totalRows; row++){
            for(int column = 0; column < totalColumns; column++){
                if(board[row][column] == startChar){
                    vector<vector<bool>> visited(totalRows, vector<bool>(totalColumns, false));
                    if(call(word, board, visited, totalRows, totalColumns, row, column, 1)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
class Solution {
private:
    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaColumn = {0, 1, 0, -1}; 

public:
    void bfs(
        vector<vector<int>>& grid, 
        int startRow, int startColumn, 
        vector<vector<bool>>& visited, int& maxArea
    ){
        queue<pair<int, int>> cellQueue;
        cellQueue.push({startRow, startColumn});
        visited[startRow][startColumn] = true;

        int currentArea = 1;
        while(!cellQueue.empty()){
            pair<int, int> currentCell = cellQueue.front();
            int currentRow = currentCell.first;
            int currentColumn = currentCell.second;
            cellQueue.pop();

            for(int i = 0; i < 4; i ++){
                int newRow = currentRow + deltaRow[i];
                int newColumn = currentColumn + deltaColumn[i];

                if(
                    newRow >= 0 && newRow < grid.size() &&
                    newColumn >= 0 && newColumn < grid[newRow].size() &&
                    !visited[newRow][newColumn] && 
                    grid[newRow][newColumn] == 1
                ){
                    cellQueue.push({newRow, newColumn});
                    visited[newRow][newColumn] = true;
                    currentArea++;
                }
            }
        }
        maxArea = max(currentArea, maxArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        } else if (grid.size() == 1 && grid[0].size() == 1){
            return grid[0][0];
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int maxArea = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int column = 0; column < grid[0].size(); column++){
                if(!visited[row][column] && grid[row][column] == 1){
                    bfs(grid, row, column, visited, maxArea);
                }
            }
        }

        return maxArea;
    }
};
class Solution {
private:
    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaColumn = {0, 1, 0, -1};

public:
    vector<vector<int>> floodFill(vector<vector<int>> grid, int startRow, int startColumn, int color) {
        int startColor = grid[startRow][startColumn];
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        queue<pair<int, int>> nodeQueue;
        nodeQueue.push({startRow, startColumn});

        while(!nodeQueue.empty()){
            pair<int, int> currentNode = nodeQueue.front();
            nodeQueue.pop();

            int currentRow = currentNode.first;
            int currentColumn = currentNode.second;

            grid[currentRow][currentColumn] = color;

            for(int i = 0; i < 4; i++){
                int newRow = currentRow + deltaRow[i];
                int newColumn = currentColumn + deltaColumn[i];

                if(
                    newRow >= 0 && newRow < grid.size() &&
                    newColumn >= 0 && newColumn < grid[0].size() &&
                    grid[newRow][newColumn] == startColor &&
                    visited[newRow][newColumn] == false
                ){
                    nodeQueue.push({newRow, newColumn});
                    visited[newRow][newColumn] = true;
                }
            }
        }

        return grid;
    }
};
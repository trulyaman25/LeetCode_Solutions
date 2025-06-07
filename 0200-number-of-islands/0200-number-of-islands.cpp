class Solution {
public:
    int bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int column){
        visited[row][column] = true;

        queue<pair<int, int>> assetQueue;
        assetQueue.push({row, column});

        vector<int> deltaRow = {0, 1, 0, -1};
        vector<int> deltaColumn = {1, 0, -1, 0};
        while(!assetQueue.empty()){
            int currentRow = assetQueue.front().first;
            int currentColumn = assetQueue.front().second;

            assetQueue.pop();
            for(int i = 0; i < 4; i++){
                int neighborRow = currentRow + deltaRow[i];
                int neighborColumn = currentColumn + deltaColumn[i];

                if(
                    neighborRow >= 0 && neighborRow < grid.size() && 
                    neighborColumn >= 0 && neighborColumn < grid[0].size() && 
                    grid[neighborRow][neighborColumn] == '1' && 
                    !visited[neighborRow][neighborColumn]
                ){
                    assetQueue.push({neighborRow, neighborColumn});
                    visited[neighborRow][neighborColumn] = true;
                }
            }
        }

        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        for(int row = 0; row < grid.size(); row++){
            for(int column = 0; column < grid[0].size(); column++){
                if(grid[row][column] == '1' && !visited[row][column]){
                    islandCount += bfs(grid, visited, row, column);
                }
            }
        }

        return islandCount;
    }
};
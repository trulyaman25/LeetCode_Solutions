class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        queue<pair<pair<int, int>, int>> assetQueue;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    assetQueue.push({{i, j}, 0});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        int minTime = 0;
        vector<int> deltaRow = {-1, 0, 1, 0};
        vector<int> deltaColumn = {0, 1, 0, -1};
        while(!assetQueue.empty()){
            pair<int, int> coordinates = assetQueue.front().first;
            int time = assetQueue.front().second;
            minTime = max(time, minTime);

            assetQueue.pop();
            for(int i = 0; i < 4; i++){
                int newRow = coordinates.first + deltaRow[i];
                int newColumn = coordinates.second + deltaColumn[i];

                if(
                    newRow >= 0 && newRow < grid.size() &&
                    newColumn >= 0 && newColumn < grid[newRow].size() &&
                    grid[newRow][newColumn] == 1 &&
                    !visited[newRow][newColumn]
                ){
                    assetQueue.push({{newRow, newColumn}, time + 1});
                    visited[newRow][newColumn] = true;
                    freshOranges--;
                }
            }
        }

        if(freshOranges > 0){
            return -1;
        }

        return minTime;
    }
};
class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int startNode){
        queue<int> nodeQueue;
        nodeQueue.push(startNode);

        visited[startNode] = true;

        while(!nodeQueue.empty()){
            int currentNode = nodeQueue.front();
            nodeQueue.pop();

            for(int neighborNode = 0; neighborNode < isConnected[currentNode].size(); neighborNode++){
                if(
                    isConnected[currentNode][neighborNode] == 1 && 
                    !visited[neighborNode]
                ){
                    visited[neighborNode] = true;
                    nodeQueue.push(neighborNode);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalNodes = isConnected.size();

        vector<bool> visited(totalNodes, false);

        int provinceCount = 0;
        for(int i = 0; i < totalNodes; i++){
            if(!visited[i]){
                provinceCount++;
                bfs(isConnected, visited, i);
            }
        }

        return provinceCount;
    }
};
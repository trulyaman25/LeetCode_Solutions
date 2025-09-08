class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, vector<bool>& visited, int startNode){
        queue<int> nodeQueue;
        nodeQueue.push(startNode);

        visited[startNode] = true;

        while(!nodeQueue.empty()){
            int currentNode = nodeQueue.front();
            nodeQueue.pop();

            for(int i = 0; i < isConnected[currentNode].size(); i++){
                if(isConnected[currentNode][i] == 1 && !visited[i]){
                    visited[i] = true;
                    nodeQueue.push(i);
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
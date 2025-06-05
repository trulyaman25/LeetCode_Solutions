class Solution {
public:
    bool bfs(vector<vector<int>>& adjacencyList, vector<pair<int, int>>& visited, int start){
        visited[start].first = 1;
        visited[start].second = true;

        queue<pair<pair<int, int>, int>> assetQueue;
        assetQueue.push({{start, true}, -1});

        while(!assetQueue.empty()){
            int currentNode = assetQueue.front().first.first;
            int currentColor = assetQueue.front().first.second;
            int parentNode = assetQueue.front().second;

            assetQueue.pop();
            for(int i = 0; i < adjacencyList[currentNode].size(); i++){
                int neighborNode = adjacencyList[currentNode][i];
                
                if(visited[neighborNode].first == -1){
                    assetQueue.push({{neighborNode, !currentColor}, currentNode});
                    visited[neighborNode].first = 1;
                    visited[neighborNode].second = !currentColor;
                } else if(visited[neighborNode].second == currentColor) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adjacencyList) {
        vector<pair<int, int>> visited(adjacencyList.size(), {-1, -1});
        for(int node = 0; node < adjacencyList.size(); node++){
            if(visited[node].first == -1){
                if(!bfs(adjacencyList, visited, node)){
                    return false;
                }
            }
        }

        return true;
    }
};
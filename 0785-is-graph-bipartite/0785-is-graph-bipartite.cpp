class Solution {
public:
    bool dfs(vector<vector<int>>& adjacencyList, vector<int>& visited, int start, int previousColor){
        int currentColor = 0;

        if(previousColor == 0 || previousColor == 2){
            currentColor = 1;
        } else {
            currentColor = 2;
        }

        visited[start] = currentColor;
        for(int i = 0; i < adjacencyList[start].size(); i++){
            int neighbor = adjacencyList[start][i];

            if(visited[neighbor] == -1){
                if(!dfs(adjacencyList, visited, neighbor, currentColor)){
                    return false;
                }
            } else if (visited[neighbor] == currentColor){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adjacencyList) {
        vector<int> visited(adjacencyList.size(), -1);
        for(int node = 0; node < adjacencyList.size(); node++){
            if(visited[node] == -1){
                if(!dfs(adjacencyList, visited, node, 0)){
                    return false;
                }
            }
        }

        return true;
    }
};
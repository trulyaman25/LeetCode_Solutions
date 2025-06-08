class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<int> inDegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int subject = prerequisites[i][0];
            int preSub = prerequisites[i][1];

            inDegree[subject]++;
            adjacencyList[preSub].push_back(subject);
        }

        queue<int> assetQueue;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                assetQueue.push(i);
            }
        }
        
        vector<int> topoSort;

        while(!assetQueue.empty()){
            int subject = assetQueue.front();
            assetQueue.pop();

            for(int i = 0; i < adjacencyList[subject].size(); i++){
                int neighbor = adjacencyList[subject][i];
                inDegree[neighbor]--;

                if(inDegree[neighbor] == 0){
                    assetQueue.push(neighbor);
                }
            }

            topoSort.push_back(subject);
        }

        if(topoSort.size() != numCourses){
            return {};
        }

        return topoSort;
    }
};
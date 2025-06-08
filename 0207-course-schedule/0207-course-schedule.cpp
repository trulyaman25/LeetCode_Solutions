class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            int subject = prerequisites[i][0];
            int prerequisiteSubject = prerequisites[i][1];

            inDegree[subject]++;
            adjacencyList[prerequisiteSubject].push_back(subject);
        }

        int toPass = numCourses;

        queue<int> assetQueue;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                assetQueue.push(i);
            }
        }

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

            toPass--;
        }

        if(toPass != 0){
            return false;
        }

        return true;
    }
};
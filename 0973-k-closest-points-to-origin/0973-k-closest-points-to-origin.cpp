class Solution {
public:
    int square(int number){
        return number * number;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> resultantVector;
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for(int i = 0; i < points.size(); i++){
            int distance = sqrt(square(points[i][0]) + square(points[i][1]));
            maxHeap.push(make_pair(distance, make_pair(points[i][0], points[i][1])));
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        while(maxHeap.size() > 0){
            vector<int> dataVector;
            dataVector.push_back(maxHeap.top().second.first);
            dataVector.push_back(maxHeap.top().second.second);

            resultantVector.push_back(dataVector);

            maxHeap.pop();
        }

        return resultantVector;
    }
};
class Solution {
public:
    int square(int number){
        return number * number;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for(int i = 0; i < points.size(); i++){
            int distance = square(points[i][0]) + square(points[i][1]);
            maxHeap.push(make_pair(distance, make_pair(points[i][0], points[i][1])));
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        points.clear();

        while(maxHeap.size() > 0){
            vector<int> dataVector = {maxHeap.top().second.first, maxHeap.top().second.second};
            points.push_back(dataVector);

            maxHeap.pop();
        }

        return points;
    }
};
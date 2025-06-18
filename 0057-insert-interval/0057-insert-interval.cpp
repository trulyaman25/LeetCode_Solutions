class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> resultantVector;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        bool inserted = false;

        for(int i = 0; i < intervals.size(); i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if(currentEnd < newStart){
                resultantVector.push_back({currentStart, currentEnd});
            } else if(currentStart > newEnd){
                if(!inserted){
                    resultantVector.push_back({newStart, newEnd});
                    inserted = true;
                }
                resultantVector.push_back({currentStart, currentEnd});
            } else {
                newStart = min(newStart, currentStart);
                newEnd = max(newEnd, currentEnd);
            }
        }

        if(!inserted){
            resultantVector.push_back({newStart, newEnd});
        }

        return resultantVector;
    }
};

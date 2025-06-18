class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int previousStart = -1;
        int previousEnd = -1;
        int removalCount = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        for(int i = 0; i < intervals.size(); i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if(previousEnd <= currentStart){
                previousStart = currentStart;
                previousEnd = currentEnd;
            } else {
                removalCount++;
            }
        }

        return removalCount;
    }
};
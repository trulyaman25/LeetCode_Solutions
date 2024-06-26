class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        sort(meetings.begin(), meetings.end());

        vector<vector<int>> resultantVector;
     resultantVector.push_back(meetings[0]);

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= resultantVector.back()[1]) {
             resultantVector.back()[1] = max(resultantVector.back()[1], meetings[i][1]);
            } else {
             resultantVector.push_back(meetings[i]);
            }
        }

        int count = resultantVector[0][0] - 1;
        for (int i = 0; i < resultantVector.size() - 1; ++i) {
            if (resultantVector[i][1] < resultantVector[i + 1][0] - 1) {
                count += resultantVector[i + 1][0] - resultantVector[i][1] - 1;
            }
        }
        count += days - resultantVector.back()[1];

        return count;
    }
};
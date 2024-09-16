class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> numbers;
        for(int i = 0; i < timePoints.size(); i++){
            int hours = stoi(timePoints[i].substr(0, 2)) * 60;
            int minutes = stoi(timePoints[i].substr(timePoints[i].size() - 2, 2));
            numbers.push_back(hours + minutes);
        }
        sort(numbers.begin(), numbers.end());

        int difference = INT_MAX;
        for(int i = 1; i < numbers.size(); i++){
            difference = min(difference, numbers[i] - numbers[i - 1]);
        }

        difference = min(difference, (1440 - numbers[numbers.size() - 1] + numbers[0]));

        return difference;
    }
};
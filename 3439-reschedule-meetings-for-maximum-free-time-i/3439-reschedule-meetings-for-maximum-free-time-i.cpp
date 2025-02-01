class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        gaps.push_back(startTime[0] - 0);
        for(int i = 0; i < startTime.size() - 1; i++){
            int difference = startTime[i + 1] - endTime[i];
            gaps.push_back(difference);
        }
        gaps.push_back(eventTime - endTime.back());

        for(auto it : gaps){
            cout << it << " " ;
        }

        int maxSum = 0;
        int currentSum = 0;
        int pointerOne = 0;
        int pointerTwo = 0;
        while(pointerTwo < k){
            currentSum += gaps[pointerTwo];
            pointerTwo++;
        }

        maxSum = max(maxSum, currentSum);

        while(pointerTwo < gaps.size()){
            currentSum += gaps[pointerTwo];
            maxSum = max(maxSum, currentSum);
            currentSum -= gaps[pointerOne];
            pointerOne++;
            pointerTwo++;
        }

        return maxSum;
    }
};
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        sort(meetings.begin(), meetings.end());

        int freeDays = 0;
        int lastMeeting = 0;
        for(int i = 0; i < meetings.size(); i++){
            if(meetings[i][0] > lastMeeting + 1){
                freeDays += meetings[i][0] - lastMeeting - 1;
            }
            lastMeeting = max(lastMeeting, meetings[i][1]);
        }

        if(lastMeeting < days){
            freeDays += days - lastMeeting;
        }

        return freeDays;
    }
};
class MyCalendarTwo {
public:
    map<int, int> hashMap;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        hashMap[startTime]++;
        hashMap[endTime]--;

        int threshold = 3;
        int ongoingMeetings = 0;
        for(auto it : hashMap){
            ongoingMeetings += it.second;
            if(ongoingMeetings >= threshold){
                hashMap[startTime]--;
                hashMap[endTime]++;

                return false;
            }
        }

        return true;
    }
};

/*
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
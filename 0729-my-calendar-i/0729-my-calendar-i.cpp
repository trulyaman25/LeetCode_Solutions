class MyCalendar {
public:
    map<int, int> hashMap;

    MyCalendar() {
        map<int, int> tempMap;

        hashMap = tempMap;
    }
    
    bool book(int startTime, int endTime) {
        hashMap[startTime]++;
        hashMap[endTime]--;

        int threshold = 1;
        int ongoingMeetings = 0;

        for(auto it : hashMap){
            ongoingMeetings += it.second;

            if(ongoingMeetings > threshold){
                hashMap[startTime]--;
                hashMap[endTime]++;

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
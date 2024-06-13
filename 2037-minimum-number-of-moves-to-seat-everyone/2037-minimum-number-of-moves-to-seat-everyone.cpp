class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int totalStudents = students.size();
        int count = 0;
        for(int i = 0; i < totalStudents; i++){
            count += max(seats[i], students[i]) - min(seats[i], students[i]);
        }
        
        return count;
    }
};
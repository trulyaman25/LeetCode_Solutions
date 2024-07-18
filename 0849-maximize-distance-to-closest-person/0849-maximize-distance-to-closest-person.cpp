class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int leftPointer = 0;
        int rightPointer = 0;
        int maxSize = 0;

        while (rightPointer < seats.size() && seats[rightPointer] == 0) {
            rightPointer++;
        }
        maxSize = rightPointer;

        while (rightPointer < seats.size()) {
            if (seats[rightPointer] == 1) {
                if (seats[leftPointer] == 1) {
                    maxSize = max(maxSize, (rightPointer - leftPointer) / 2);
                }
                leftPointer = rightPointer;
            }
            rightPointer++;
        }

        int seatSize = seats.size();
        maxSize = max(maxSize, seatSize - leftPointer - 1);

        return maxSize;
    }
};

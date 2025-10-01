class Solution {
public:
    int numWaterBottles(int numBottles, int threshold) {
        int maxBottles = numBottles;
        int filledBottles = numBottles;
        int emptyBottles = 0;

        while (filledBottles > 0) {
            emptyBottles += filledBottles;
            filledBottles = emptyBottles / threshold;
            emptyBottles %= threshold;
            maxBottles += filledBottles;
        }

        return maxBottles;
    }
};

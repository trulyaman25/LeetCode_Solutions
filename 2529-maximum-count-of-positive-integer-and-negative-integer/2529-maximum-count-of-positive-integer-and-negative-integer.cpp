class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        int lastNegativeNumber = -1;
        while (pointerOne <= pointerTwo) {
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;

            if (nums[mid] < 0) {
                lastNegativeNumber = mid;
                pointerOne = mid + 1;
            } else {
                pointerTwo = mid - 1;
            }
        }

        pointerOne = 0;
        pointerTwo = nums.size() - 1;
        int firstPositiveNumber = nums.size();
        while (pointerOne <= pointerTwo) {
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;

            if (nums[mid] > 0) {
                firstPositiveNumber = mid;
                pointerTwo = mid - 1;
            } else {
                pointerOne = mid + 1;
            }
        }

        int positiveCount = nums.size() - firstPositiveNumber;
        int negativeCount = lastNegativeNumber + 1;

        return max(positiveCount, negativeCount);
    }
};
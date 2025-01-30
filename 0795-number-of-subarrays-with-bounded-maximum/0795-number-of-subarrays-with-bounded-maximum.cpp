class Solution {
public:
    int countSubArray(vector<int>& nums, int startIndex, int endIndex, int lowerLimit, int upperLimit) {
        double  totalSubArray =(double ) ((double)(endIndex - startIndex + 1) * (double)(endIndex - startIndex + 2)) / 2;
        int pointerOne = 0;
        int pointerTwo = 0;

        int invalidSubArray = 0;
        int tempCount = 0;
        for (int i = startIndex; i < endIndex + 1; i++) {
            if (nums[i] < lowerLimit) {
                tempCount++;
            } else {
                // 0(1) /2
                if (tempCount > 0) {
                    invalidSubArray += (tempCount * (tempCount + 1) / 2);
                    tempCount = 0;
                }
            }
        }

        if (tempCount > 0) {
            invalidSubArray += (tempCount * (tempCount + 1)) / 2;
        }

        return (int)(totalSubArray - (double)invalidSubArray);
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int pointerOne = 0;
        int pointerTwo = 0;
        int resultantCount = 0;
        int n= nums.size();

        while (pointerTwo < nums.size()) {
            if (nums[pointerTwo] > right) {
                if (pointerOne < pointerTwo) {
                    resultantCount += countSubArray(nums, pointerOne, pointerTwo - 1, left, right);
                }
                pointerTwo++;
                pointerOne = pointerTwo;
            } else {
                pointerTwo++;
            }
        }

        if (pointerOne < n) {
            resultantCount += countSubArray(nums, pointerOne, pointerTwo - 1, left, right);
        }

        return resultantCount;
    }
};

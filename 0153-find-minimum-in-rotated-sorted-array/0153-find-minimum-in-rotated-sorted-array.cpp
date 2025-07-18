class Solution {
public:
    int findMin(vector<int>& nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        int minValue = INT_MAX;
        while(leftPointer <= rightPointer){
            int mid = leftPointer + (rightPointer - leftPointer) / 2;
            minValue = min(nums[mid], minValue);

            if(nums[leftPointer] <= nums[mid]){
                if(nums[mid] > nums[rightPointer]){
                    leftPointer = mid + 1;
                } else {
                    rightPointer = mid - 1;
                }
            } else {
                if(nums[mid] <= nums[rightPointer]){
                    rightPointer = mid - 1;
                } else {
                    leftPointer = mid + 1;
                }
            }
        }

        return minValue;
    }
};
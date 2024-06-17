class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        int index = 0;
        while(leftPointer <= rightPointer){
            int mid = (leftPointer + rightPointer) / 2;
            if(target > nums[mid]){
                leftPointer = mid + 1;
                index = leftPointer;
            } else if(target < nums[mid]){
                rightPointer = mid - 1;
                index = rightPointer;
            } else {
                return mid;
            }
        }

        return leftPointer;
    }
};
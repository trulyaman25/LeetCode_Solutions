class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        while(leftPointer <= rightPointer){
            int mid = leftPointer + (rightPointer - leftPointer) / 2;

            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] > target){
                rightPointer = mid - 1;
            } else if (nums[mid] < target){
                leftPointer = mid + 1;
            }
        }

        return leftPointer;
    }
};
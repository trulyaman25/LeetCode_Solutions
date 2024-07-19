class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        while (leftPointer <= rightPointer) {
            int mid = leftPointer + (rightPointer - leftPointer) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if(nums[leftPointer] <= nums[mid]){
                if (nums[leftPointer] <= target && target < nums[mid]) {
                    rightPointer = mid - 1;
                } else {
                    leftPointer = mid + 1;
                }
            } else {
                if (nums[rightPointer] >= target && nums[mid] < target) {
                    leftPointer = mid + 1;
                } else {
                    rightPointer = mid - 1;
                }
            }
        }

        return -1;
    }
};
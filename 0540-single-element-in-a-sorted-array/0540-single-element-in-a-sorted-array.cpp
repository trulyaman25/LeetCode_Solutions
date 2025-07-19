class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        int mid = -1;
        while(leftPointer < rightPointer){
            mid = leftPointer + (rightPointer - leftPointer) / 2;

            if(mid % 2 == 0){
                if(mid < nums.size() - 1 && nums[mid] == nums[mid + 1]){
                    leftPointer = mid + 2;
                } else {
                    rightPointer = mid;
                }
            } else {
                if(nums[mid] != nums[mid + 1]){
                    leftPointer = mid + 1;
                } else {
                    rightPointer = mid;
                }
            }
        }

        return nums[leftPointer];
    }
};
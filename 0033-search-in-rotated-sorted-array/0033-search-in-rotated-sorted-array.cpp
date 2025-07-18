class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        while (pointerOne <= pointerTwo) {
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int midValue = nums[mid];

            if (midValue == target) {
                return mid;
            } else if(midValue >= nums[pointerOne]){
                if (nums[pointerOne] <= target && target < midValue) {
                    pointerTwo = mid - 1;
                } else {
                    pointerOne = mid + 1;
                }
            } else {
                if (nums[pointerTwo] >= target && midValue < target) {
                    pointerOne = mid + 1;
                } else {
                    pointerTwo = mid - 1;
                }
            }
        }

        return -1;
    }
};
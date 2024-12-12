class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        int mid = pointerOne + (pointerTwo - pointerOne) / 2;
        while(pointerOne <= pointerTwo){
            mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int value = nums[mid];

            if(value == target){
                return mid;
            } else if (target > nums[mid]) {
                pointerOne = mid + 1;
            } else {
                pointerTwo = mid - 1;
            }
        }
        
        return pointerOne;
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        int mid = 0;
        while(pointerOne <= pointerTwo){
            mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int value = nums[mid];

            if(value >= nums[pointerOne]){
                if(nums[pointerTwo] <= nums[pointerOne]){
                    pointerOne = mid + 1;
                } else {
                    pointerTwo = mid - 1;
                }
            } else {
                if(nums[pointerTwo] > value){
                    pointerTwo = mid;
                } else {
                    pointerOne = mid + 1;
                }
            }
        }

        return nums[mid];
    }
};
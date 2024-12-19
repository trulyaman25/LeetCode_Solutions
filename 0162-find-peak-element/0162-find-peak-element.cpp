class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        if(nums.size() == 1){
            return 0;
        }

        if(nums.size() == 2){
            return nums[0] < nums[1];
        }

        while(pointerOne <= pointerTwo){
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int value = nums[mid];

            if(mid == 0){
                if(value > nums[mid + 1]){
                    return mid;
                }
            } else if(mid == nums.size()){
                if(value > nums[mid - 1]){
                    return mid;
                }
            }
            
            if (nums[mid - 1] < value && value > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] > value && value > nums[mid + 1]) {
                pointerTwo = mid;
            } else if (nums[mid - 1] < value && value < nums[mid + 1]) {
                pointerOne = mid + 1;
            } else {
                pointerTwo = mid;
            }
        }

        return -1;
    }
};
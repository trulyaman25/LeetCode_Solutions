class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        while(pointerOne <= pointerTwo){
            int mid = (pointerOne + pointerTwo) / 2;
            
            if(nums[mid] == target){
                return mid;
            } else if (nums[mid] > target){
                pointerTwo = mid - 1;
            } else {
                pointerOne = mid + 1;
            }
        }

        return -1;
    }
};
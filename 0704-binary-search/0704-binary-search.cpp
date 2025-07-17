class Solution {
public:
    int getIndex(vector<int>& nums, int& target, int pointerOne, int pointerTwo){
        if(pointerOne > pointerTwo){
            return -1;
        }

        int mid = (pointerOne + pointerTwo) / 2;
 
        if(nums[mid] == target){
            return mid;
        } else if (nums[mid] > target){
            return getIndex(nums, target, pointerOne, mid - 1);
        } else if (nums[mid] < target) {
            return getIndex(nums, target, mid + 1, pointerTwo);
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        return getIndex(nums, target, pointerOne, pointerTwo);
    }
};
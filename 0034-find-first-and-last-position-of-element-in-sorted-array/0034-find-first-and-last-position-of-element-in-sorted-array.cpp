class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> resultantVector = {-1, -1};
        int pointerOne = 0;
        int pointerTwo = nums.size() - 1;

        while(pointerOne <= pointerTwo){
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int value = nums[mid];

            if(value == target){
                resultantVector[0] = mid;
                pointerTwo = mid - 1;
            } else if (value > target) {
                pointerTwo = mid - 1;
            } else {
                pointerOne = mid + 1;
            }
        }

        pointerOne = 0;
        pointerTwo = nums.size() - 1;
        while(pointerOne <= pointerTwo){
            int mid = pointerOne + (pointerTwo - pointerOne) / 2;
            int value = nums[mid];

            if(value == target){
                resultantVector[1] = mid;
                pointerOne = mid + 1;
            } else if (value > target) {
                pointerTwo = mid - 1;
            } else {
                pointerOne = mid + 1;
            }
        }


        if(resultantVector.size() == 0){
            return {-1, -1};
        }

        return resultantVector;
    }
};
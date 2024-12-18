//Brute Force
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         if(nums.size() == 1){
//             return nums.back();
//         }

//         for(int i = 0; i < nums.size(); i += 2){
//             if(i == nums.size() - 1){
//                 return nums.back();
//             }

//             if(nums[i] != nums[i + 1]){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

//Optimized Solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int leftPointer = 0;
        int rightPointer = nums.size() - 1;

        while (leftPointer < rightPointer) {
            int mid = (leftPointer + rightPointer) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            
            if (nums[mid] != nums[mid + 1]) {
                rightPointer = mid;
            } else {
                leftPointer = mid + 2;
            }
        }
        return nums[leftPointer];
    }
};
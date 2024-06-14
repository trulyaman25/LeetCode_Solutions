//BRUTE FORCE SOLUTION
// class Solution {
// public:
//     int minIncrementForUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int count = 0;
//         for(int i = 1; i < nums.size(); i++){
//             while(nums[i] <= nums[i - 1]){
//                 nums[i]++;
//                 count++;
//             }
//         }

//         return count;
//     }
// };

//OPTIMIZED SOLUTION
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                int stepsRequired = nums[i - 1] - nums[i] + 1;
                nums[i] += stepsRequired;
                count += stepsRequired;
            }
        }

        return count;
    }
};
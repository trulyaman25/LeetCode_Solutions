//2 POINTER APPROACH (ARRANGES ALL THE VAL AT THE BACK OF THE VECTOR)
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int pointerOne = 0;
//         int pointerTwo = nums.size() - 1;
//         int valuableCount = 0;

//         while(pointerOne <= pointerTwo){
//             if(nums[pointerOne] == val && nums[pointerTwo] != val){
//                 swap(nums[pointerOne], nums[pointerTwo]);
//                 valuableCount++;
//                 pointerOne++;
//                 pointerTwo--;
//             } else if (nums[pointerTwo] == val) {
//                 pointerTwo--;
//                 valuableCount++;
//             } else {
//                 pointerOne++;
//             }
//         }

//         return nums.size() - valuableCount;
//     }
// };

//1 POINTER APPROACH (REMOVES THE OCCURRENCES OF VAL FROM THE VECTOR)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pointer = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[pointer] = nums[i];
                pointer++;
            }
        }

        return pointer;
    }
};
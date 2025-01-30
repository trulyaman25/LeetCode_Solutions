class Solution {
public:
    int countSubArray(vector<int>& nums, int goal){
        int pointerOne = 0;
        int pointerTwo = 0;

        int sum = 0;
        int subArrayCount = 0;
        while(pointerTwo < nums.size()){
            sum += nums[pointerTwo];

            while(sum > goal && pointerOne <= pointerTwo){
                sum -= nums[pointerOne];
                pointerOne++;
            }

            subArrayCount += pointerTwo - pointerOne + 1;
            pointerTwo++;
        }

        return subArrayCount;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubArray(nums, goal) - countSubArray(nums, goal - 1);
    }
};
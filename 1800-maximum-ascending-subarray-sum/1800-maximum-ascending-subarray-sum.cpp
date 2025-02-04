class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int maxSum = 0;
        int currentSum = 0;

        while(pointerTwo < nums.size()){
            if(pointerTwo > 0){
                if(nums[pointerTwo - 1] >= nums[pointerTwo]){
                    maxSum = max(maxSum, currentSum);
                    currentSum = nums[pointerTwo];
                    pointerOne = pointerTwo;
                } else {
                    currentSum += nums[pointerTwo];
                }
            } else {
                currentSum += nums[pointerTwo];
            }
            maxSum = max(maxSum, currentSum);
            pointerTwo++;
        }

        return maxSum;
    }
};
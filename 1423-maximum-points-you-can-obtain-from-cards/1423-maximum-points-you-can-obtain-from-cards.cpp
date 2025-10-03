class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < k; i++){
            leftSum += nums[i];
        }


        int maxSum = leftSum;
        for(int i = 0; i < k; i++){
            rightSum += nums[nums.size() - i - 1];
            leftSum -= nums[k - i - 1];
            maxSum = max(leftSum + rightSum, maxSum);
        }

        return maxSum;
    }
};
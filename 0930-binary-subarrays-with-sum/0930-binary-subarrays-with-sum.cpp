class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int countOne = calculateSubArray(nums, goal);
        int countTwo = calculateSubArray(nums, goal - 1);

        return countOne - countTwo;
    }

    int calculateSubArray(vector<int>& nums, int goal) {
        int count = 0;
        int sum = 0;

        int pointerOne = 0;
        for (int pointerTwo = 0; pointerTwo < nums.size(); pointerTwo++) {
            sum += nums[pointerTwo];

            while (sum > goal && pointerOne <= pointerTwo) {
                sum -= nums[pointerOne];
                pointerOne++;
            }

            count += (pointerTwo - pointerOne + 1);
        }

        return count;
    }
};